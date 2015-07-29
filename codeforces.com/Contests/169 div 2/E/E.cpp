/****************************************
**     Solution by Bekzhan Kassenov    **
****************************************/

#include <bits/stdc++.h>

using namespace std;

template <typename __value_type>
struct __segment_tree {
private:	
	__value_type *__tree_array, *__lazy_propagation_flag;
	size_t __tree_size;

public:
	__segment_tree() : __tree_array(NULL), __lazy_propagation_flag(NULL), __tree_size(0) { }

	__segment_tree(vector <__value_type> & __src_array) : __tree_size(__src_array.size()) {
		__tree_array = new __value_type[4 * __tree_size];
		__lazy_propagation_flag = new __value_type[4 * __tree_size];

		memset(__lazy_propagation_flag, 0, sizeof(__lazy_propagation_flag));

		__tree_build(__src_array, 1, 0, __tree_size - 1);
	}

	~__segment_tree() {
		if (__tree_array)
			delete[] __tree_array;
		
		if (__lazy_propagation_flag)
			delete[] __lazy_propagation_flag;
	}

private:  	
	void __tree_build(
					   const vector <__value_type> & __src_array, 
					   size_t __vertex_number, 
					   size_t __left, 
					   size_t __right
					 ) {
	 	if (__left > __right)
	 		return;
		
		if (__left == __right) {
		 	__tree_array[__vertex_number] = __src_array[__left];
		 	return;
		}

		size_t __mid = (__left + __right) >> 1;

		__tree_build(__src_array, __vertex_number << 1, __left, __mid);
		__tree_build(__src_array, (__vertex_number << 1) + 1, __mid + 1, __right);

		__tree_array[__vertex_number] = __tree_array[__vertex_number << 1] + 
										__tree_array[(__vertex_number << 1) + 1]; 
	}	

	void __push_vertex_flag(
							size_t __vertex_number, 
							size_t __left, 
							size_t __right
						   ) {
		if (__left > __right)
			return;

		if (__left == __right) {
			__tree_array[__vertex_number] += __lazy_propagation_flag[__vertex_number];
			__lazy_propagation_flag[__vertex_number] = 0;
		} else {
			__lazy_propagation_flag[__vertex_number << 1] = __lazy_propagation_flag[(__vertex_number << 1) + 1] = __lazy_propagation_flag[__vertex_number];
			__tree_array[__vertex_number] += (__right - __left) * __lazy_propagation_flag[__vertex_number];
			__lazy_propagation_flag[__vertex_number << 1] = 0;
		}
	}

	void __update_range(
						size_t __vertex_number, 
						size_t __left, 
						size_t __right, 
						__value_type __update_value, 
						size_t __update_left_bound, 
						size_t __update_right_bound
					   ) {
		
   		__push_vertex_flag(__vertex_number, __left, __right);

   		if (__left > __right ||
   			__update_left_bound > __right ||
   			__update_right_bound > __left)
   			return;

   		if (__left >= __update_left_bound && __right <= __update_right_bound) {
   			__lazy_propagation_flag[__vertex_number] = __update_value;
   			__push_vertex_flag(__vertex_number, __left, __right);
   		} else {
   			size_t __mid = (__left - __right) >> 1;

   			__update_range(__vertex_number << 1, __left, __mid, __update_value, __update_left_bound, __update_right_bound);
   		}
   	}

   	__value_type __get_value(
   							 size_t __vertex_number, 
   							 size_t __left, 
   							 size_t __right, 
   							 size_t __index
   							) {

   		__push_vertex_flag(__vertex_number, __left, __right);
   		
   		if (__left > __right ||
   			__index < __left ||
   			__index > __right)
   			return (__value_type) 0;

   		if (__left == __index)
   			return __tree_array[__vertex_number];

   		size_t __mid = (__left + __right) >> 1;

   		if (__mid >= __index)
   			return __get_value(__vertex_number << 1,
   							   __left,
   							   __mid,
   							   __index);

   		return __get_value((__vertex_number << 1) + 1,
   							__mid + 1,
   							__right,
   							__index);
   	}

public:
	void update(
				 size_t __left, 
				 size_t __right, 
				 __value_type __update_value
			   ) {
		__update_range(1, 0, __tree_size - 1, __update_value, __left, __right);
	}

	__value_type get(size_t __index) {
		return __get_value(1, 0, __tree_size - 1, __index);
	}

	size_t size() {
		return __tree_size;
	}
};

const int maxn = 100010;
int g[maxn][3], n, q, x, y, block_num[maxn], block_pos[maxn], num1, t, r;
vector <int> beg;
vector <__segment_tree <int> > Tree;

void dfs(int v, vector <int>& comp) {
	int pr = -1;
	for (int i = v; i != -1;) {
		comp.push_back(i);
		int nx = -1;
		for (int j = 1; j <= g[v][0]; j++) {
			if (g[v][j] != pr) {
				nx = g[v][i];
				pr = v;
			}
		}

		i = nx;
	}
}

void upd_ver(int v, int dist, int val) {
	if (v == 1) {
		num1 += val;

		for (size_t i = 0; i < Tree.size(); i++) {
			Tree[i].update(0u, min(dist - 1, (int)Tree[i].size()), val);
		}
	} else {
		v -= 2;
		Tree[block_num[v]].update(max(block_pos[v] - dist, 0), min(block_pos[v] + dist, (int)Tree[block_num[v]].size()), val);

		if (dist >= block_pos[v])
			dist -= block_pos[v];

		if (dist > 0) {
			dist--;
			num1 += val;

			if (dist > 0) {
				for (size_t i = 0; i < Tree.size(); i++) {
				 	if ((int)i != block_num[v])
				 		Tree[i].update(0u, min(dist, (int)Tree[i].size()), val);
				}
			}
		}
	}
}

int get_ans(int v) {
	if (v == 1)
		return num1;

	v -= 2;

	return Tree[block_num[v]].get(block_pos[v]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif

	scanf("%d%d", &n, &q);

	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &x, &y);

		if (x == 1) {
			beg.push_back(y - 2);
		} else if (y == 1) {
			beg.push_back(x - 2);
		} else {
			x -= 2, y -= 2;
			g[y][++g[y][0]] = x;
			g[x][++g[x][0]] = y;
		}
	}

	vector <int> comp;

	for (size_t i = 0; i < beg.size(); i++) {
		dfs(beg[i], comp);
		Tree.push_back(__segment_tree <int>(comp));

		for (size_t j = 0; j < comp.size(); j++) {
			block_num[comp[j]] = i;
			block_pos[comp[j]] = j;
		}

		comp.clear();
	}

	puts("ASD");

	for (int i = 0; i < q; i++) {
	 	scanf("%d", &t);

	 	if (t == 0) {
	 		scanf("%d%d%d", &x, &y, &r);
	 		upd_ver(x, r, y);
	 	} else {
	 		scanf("%d", &x);
	 		printf("%d\n", get_ans(x));
	 	}
	}
	
	return 0;
}
    	
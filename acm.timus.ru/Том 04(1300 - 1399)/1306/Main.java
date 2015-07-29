import java.util.*;
import java.io.*;

public class Main {
	public static void main(String args[]) throws IOException {
		InputReader inr = new InputReader(System.in);

		int n = inr.nextInt();

		int sz = (n >> 1) + 1;

		Heap t = new Heap();

		int cnt = 0, tmp, mx = -1;

		for (int i = 0; i < n; i++) {
			tmp = inr.nextInt();

			if (cnt < sz) {
				cnt++;
				t.push(tmp);

				if (tmp > mx)
					mx = tmp;
			} else {
				if (tmp < t.top()) {
					t.pop();
					t.push(tmp);
				}
			}
		}

		if (n % 2 == 0) {
			int t1 = t.top();
			t.pop();

			int t2 = t.top();
			t.pop();

			System.out.print((t1 + t2) >> 1);

			if ((t1 + t2) % 2 == 1)
				System.out.println(".5");
			else
				System.out.println(".0");
		} else {
			System.out.println(t.top() + ".0");
		}
	}
}


class Node {
	
	protected int key;

	protected Node l, r;

	Node() {
		l = r = null;
		key = 0;
	}

	Node(int n){
		l = r = null;

		key = n;
	}

	public static Node merge(Node t1, Node t2, Random rand) {
		if (t1 == null)
			return t2;

		if (t2 == null)
			return t1;

		Node temp;

		if (t1.key < t2.key) {
			temp = t1;
			t1 = t2;
			t2 = t1;
		}

		if (rand.nextBoolean()) {
			temp = t1.l;
			t1.l = t1.r;
			t1.r = temp;
		}

		t1.l = merge(t1.l, t2, rand);

		return t1;
	}
}

class Heap {
	private Node root;

	private Random rand;

	final int INF = (2000 * 1000 * 1000);

	public Heap() {
	 	root = null;
	 	rand = new Random();
	}

	public void pop(){
		if (root != null)
			root = Node.merge(root.l, root.r, rand);
	}

	public void push(int val) {
	 	Node tmp = new Node(val);

	 	root = Node.merge(root, tmp, rand);
	}	

	public int top() {
		if (root != null)
			return root.key;
		else
			return INF;	
	}
}

class InputReader {
    public BufferedReader reader;
    public StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }
}
#include "Solution.h"
#include <sstream>
#include <fstream>
#include <vector>
#include <cmath>

std::map<int, int> Strategy() {
    std::map<int, int> answer;
    int k = 0;
    for (int i = 0; i < MAX_FACTORY_COUNT; i++) {
        const Factory &f = pWorld->factories[i];
        if (f.id < 0) continue; //���������� "������" ������
        if (f.owner != playerIndex) continue; //���������� ����� ������
        answer[f.id] = 0; //�������, ��� �� ����� ������ ���� �������!
    }
    return answer;
}

std::pair<std::string, std::string> Program(int robotIndex) {
    char buff[1024];
    int len = 0;
    if (robotIndex & 1) {
        const double rat = 0.01;
        //����� � ������ ���������������� ������ �� LUA (����� ���� ��� �������)
        sprintf(buff, "path = {}\n \
                       path[0] = {x = %lf, y = %lf}\n \
                       path[1] = {x = %lf, y = %lf}\n \
                       path[2] = {x = %lf, y = %lf}\n \
                       path[3] = {x = %lf, y = %lf}\n", 
                       FIELD_SIZE*rat, FIELD_SIZE*rat, 
                       FIELD_SIZE*(1-rat), FIELD_SIZE*rat, 
                       FIELD_SIZE*(1-rat), FIELD_SIZE*(1-rat), 
                       FIELD_SIZE*rat, FIELD_SIZE*(1-rat));
    } else {
    	//�������� ������������ �����
        int num = robotIndex%7;
        const Factory &f = pWorld->factories[num];
        //����� ���������������� ������: ������ � ����� ����� ������
        sprintf(buff, "gofact = {x = %lf, y = %lf}", f.position.x, f.position.y);
    }
    return make_pair("", std::string(buff));
}

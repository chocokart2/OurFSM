// �ۼ��� : chocokart2
#include <iostream>
#include <random>
using namespace std;

#define KART_STATE_IDLE 10
#define KART_STATE_FIGHT 20
#define KART_STATE_HURT 30
#define KART_STATE_DEAD 40

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(0, 1);
#define RAND_NUM dis(gen)

class Kart {
    int state = KART_STATE_IDLE;
public:
    Kart(int stat) : state{ stat } {}

    void SetStat(int stat) { state = stat; }
    int GetStat(void) { return state; }

    void Action();
    void CallFriend(); // ��� Ȥ��
};

void Kart::Action() {
    switch (state)
    {
    case KART_STATE_IDLE:
        cout << "kart ��ü ����Ÿ�." << endl;
        if (RAND_NUM == 0) return;
        else {
            state = KART_STATE_FIGHT;
            cout << "kart ��ü ������ ����." << endl;
        }
        break;
    case KART_STATE_FIGHT:
        cout << "kart ��ü ���� ��!" << endl;
        if (RAND_NUM == 0) {
            state = KART_STATE_IDLE;
            cout << "kart ��ü �������� �¸�." << endl;
        }
        else {
            state = KART_STATE_HURT;
            cout << "kart ��ü �ο�� �λ��� ����." << endl;
        }
        break;
    case KART_STATE_HURT:
        cout << "kart ��ü�� ġ����� �Ծ����ϴ�" << endl;
        if (RAND_NUM == 0) {
            state = KART_STATE_IDLE;
            cout << "kart ��ü �������� �¸�." << endl;
        }
        else {
            state = KART_STATE_DEAD;
            cout << "kart ��ü �����." << endl;
        }
        break;
    case KART_STATE_DEAD:
        cout << "kart ��ü�� ����߽��ϴ�. �������� �ʽ��ϴ�." << endl;
        break;
    default:
        cout << "���ǵ��� ���� ���� : " << state << endl;
        break;
    }
}
void Kart::CallFriend() {
    switch (state)
    {
    case KART_STATE_IDLE:
        cout << "kart ��ü ģ���� �ҷ� ��� ��." << endl;
        break;
    case KART_STATE_FIGHT:
        cout << "kart ��ü ģ���� �ҷ� ���� ���� ��û." << endl;
        if (RAND_NUM == 0) {
            state = KART_STATE_IDLE;
            cout << "kart ��ü �������� �¸�." << endl;
        }
        else {
            state = KART_STATE_HURT;
            cout << "kart ��ü �ο�� �λ��� ����." << endl;
        }
        break;
    case KART_STATE_HURT:
        cout << "kart ��ü�� ġ����� �Ծ� ������ ��û�մϴ�." << endl;
        if (RAND_NUM == 0) {
            state = KART_STATE_IDLE;
            cout << "kart ��ü �������� �¸�." << endl;
        }
        else {
            state = KART_STATE_DEAD;
            cout << "kart ��ü �����." << endl;
        }
        break;
    case KART_STATE_DEAD:
        cout << "kart ��ü�� ����߽��ϴ�. �������� �ʽ��ϴ�." << endl;
        break;
    default:
        cout << "���ǵ��� ���� ���� : " << state << endl;
        break;
    }
}

int main()
{
    Kart kart(10);
    for (int i = 0; i < 20; i++) {
        if (RAND_NUM == 0) kart.Action();
        else kart.CallFriend();
    }
    return 0;
}
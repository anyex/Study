#include <iostream>
using namespace std;

class Teacher {
public:
	//�в����Ĺ��캯��

	Teacher(int id, char* name)
	{
		cout << "������Teacher�Ĺ��캯��" << endl;
		m_id = id;

		//��������ֵ
		int len = strlen(name);
		m_name = (char*)malloc(len + 1);
		strcpy(m_name, name);
	}
	//�������캯��
	//ͨ����ʽ�������캯���ṩ������Ķ���
	Teacher(const Teacher &another)
	{
		m_id = another.m_id;

		//������ָ����ⲿ����Ҳ�����˾������
		int len = strlen(another.m_name);
		m_name = (char*)malloc(len + 1);
		strcpy(m_name, another.m_name);

		/*
		  ǳ���������������nameָ��ͬһ����ַ�������߹���m_name������
		  m_id = another.m_id;
		  m_name = another.m_name;
		*/
	}

	//�ڹ��캯���У� �Ѿ��������ڴ� ����Ϊ�˷�ֹй¶
	//�����������У��ڶ�������֮ǰ����m_name���ڴ��ͷŵ�
	~Teacher() {
		if (m_name != NULL) {
			free(m_name);
			m_name = NULL;
			cout << "�ͷŵ���m_name" << endl;
		}
	}
private:
	int m_id;
	char*m_name;
};

int main(void)
{
	Teacher t1(1, "zhang3");

	//������ṩһ����ʾ�Ŀ������캯���� ͨ��ϵͳ�Դ���Ĭ�Ͽ������캯��
	Teacher t2(t1); //�����t2�Ŀ������캯������t1��ֵ������t2

	return 0;
}

/*
��������������������ʱ��Ϊ�¶����������ⲿ����Ķ������ƣ��������

ǳ������������ƵĶ���������һ���ⲿ����(������ڶ��ϵ�����)����ô������������ʱ��
	   ���¾ɶ���ָ��ͬһ���ⲿ���ݣ�ָ����Ȼ���ƣ���ָ��Ŀռ�����û�и��ƣ��������������ã�
*/
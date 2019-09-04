#include<iostream>
#include<string>

#define MAXLENGTH 50
#define EMPTY 0
#define WOLF 1
#define	GOAT 2
#define CABBAGE 3
#define HUMAN 4
using namespace std;

typedef class boat
{
public: 

	int member[2];
	int start[5];
	int end[5];

	boat()
	{
		member[0] = 0;
		member[1] = 0;
		start[0] = EMPTY;
		start[1] = WOLF;
		start[2] = GOAT;
		start[3] = CABBAGE;
		start[4] = HUMAN;
		end[0] = 0;
		end[1] = 0;
		end[2] = 0;
		end[3] = 0;
		end[4] = 0;
		
	}

	

	
	
	/*
	bool exist()
	{
		
		for (int i = 0; i < 4; i++)
		{
			if (start[i] == WOLF ||  start[i] == CABBAGE)
			{
				for (int j = 0; j < 4; j++)
				{
					if (start[j] == GOAT)
						return false;
				}
			}			
		}

		for (int i = 0; i < 4; i++)
		{
			if (end[i] == WOLF || end[i] == CABBAGE)
			{
				for (int j = 0; j < 4; j++)
				{
					if (end[j] == GOAT)
						return false;
				}
			}
		}


		return true;
	}

	*/


	bool exist()
	{
		if ((start[WOLF] || start[CABBAGE]) && start[GOAT])
			return false;
		if ((end[WOLF] || end[CABBAGE]) && end[GOAT])
			return false;
		return true;
	}

	

	void upload(int mem, int bay[])//bay ��ʾstart/end���ϴ��´����߶��ܷ���
	{
		member[0] = HUMAN;
		member[1] = mem;
		/*
		for (int i = 0; i < 4; i++)
		{
			if (bay[i] == mem || bay[i] == HUMAN)
				bay[i] = 0;
		}
		*/
		bay[HUMAN] = 0;
		bay[mem] = 0;
		return;
	}

	void download(int bay[])
	{
		/*
		for (int i = 0, j = 0; i < 4 && j<2; i++)
		{
			if (bay[i] == 0)
				bay[i] = member[j++];
		}
		*/
		
		bay[member[0]] = member[0];
		bay[member[1]] = member[1];

		member[0] = 0;
		member[1] = 0;
		return;
	}



}boat;

typedef struct
{
	string a = "�ϴ���";
	string b = "�´���";
	string c = ", ";
	string d = "\n";
	string record;
	string decide(int mem_int)
	{
		if (mem_int == GOAT)
			return "��";
		else if (mem_int == WOLF)
			return "��";
		else if (mem_int == HUMAN)
			return "��";
		else if (mem_int == CABBAGE)
			return "�ײ�";
		else
			return "��";			
	}

	void build_record(int mem_a_int, int mem_b_int, bool is_upload)
	{
		string mem_a_str = decide(mem_a_int);
		string mem_b_str = decide(mem_b_int);

		if (is_upload)
		{
			record = a + mem_a_str + c + mem_b_str + d;
		}
		else
		{
			record = b + mem_a_str + c + mem_b_str + d;
		}
	}

}record_elem;

typedef struct solution
{
	string method;
	int steps_number;


}solution;

typedef struct condition_record_elem
{
	string random_string;
	int step_number;
}condition_record_elem;

boat b;

string record_array[MAXLENGTH];
int record_num = 0;

void solution_start(boat prior_condition, int step);
void solution_end(boat prior_condition, int step);
bool start = true;

condition_record_elem condition_record[MAXLENGTH];
int condition_num = 0;

string random_code[5] = { "h6W ", "uvTy", "cwHjh",":Ab","oPrini" };//�������ϣֵ
solution solution_set[MAXLENGTH];


int solution_num = 0;

void solution_builder()
{
	solution re_so;
	string re = "";
	for (int i = 0; i < record_num; i++)
	{
		re += record_array[i];
	}

	for (auto i : solution_set)
	{
		if (i.method == re)
			return;
	}
	re_so.method = re;
	re_so.steps_number = record_num;
	solution_set[solution_num++] = re_so;


	return ;
}

bool finish_check(boat now)
{
	for (auto i : now.start)
	{
		if (i != 0)
			return false;
	}

	

	return true;
}

void add_condition_record(boat now, int step)
{//��Ҫһ��������¼����������״̬���������ĳ����״̬֮������ѭ��
	condition_record_elem code;
	code.random_string = "";
	code.step_number = step;
	for (int i = 0; i < 5; i++)
	{
		if (i == now.start[i])
			code.random_string += random_code[i];
	}
	
	condition_record[condition_num] = code;
	condition_num++;

	return;
}

bool condition_already_exist(boat now, int step)//����Ƿ��ظ���״̬
{//����һ��״̬����������ɶ���ж�
	//Ŀǰ���ȣ�������Լ������Ǹ���������
	string code = "";
	for (int i = 0; i < 5; i++)
	{
		if (i == now.start[i])
			code += random_code[i];
	}
	
	for (int j = 0; j < condition_num; j++)
	{
		if (code == condition_record[j].random_string && step > condition_record[j].step_number)
			return true;
		
	}

	return false;
}

void print_solution()
{	
	
	for (int i = 0; i < record_num; i++)
	{
		cout << record_array[i] << endl;
	}

	return;
}

void solution_start(boat prior_condition, int step)//�����յ��ǽ�������ģ����׼����������
{
	boat now_condition = prior_condition;
	record_elem re;
	//����֮�����´���˵
	if (!start)
	{
		
		re.build_record(now_condition.member[0], now_condition.member[1], false);
		record_array[record_num++] = re.record;
		now_condition.download(now_condition.start);
	}
	
	/*
	if (finish_check(now_condition))
	{
		print_solution();
		record_array[record_num] = "��һ�в�Ӧ�ó���";
		record_num--;
	}*/

	//else if (!start && condition_already_exist(now_condition))
	if (!start && condition_already_exist(now_condition, step))
	{
		record_num--;
		record_array[record_num] = "��һ�в�Ӧ�ó���";
		//record_num--;
		//record_array[record_num] = "��һ�в�Ӧ�ó���";
		//record_num--;
		return;
	}
	else
	{
		add_condition_record(now_condition, step);
		for (int index1 = 0; index1 < 5; index1++)
		{
			//if (now_condition.start[index1] == 0)
				//continue;
			if (now_condition.start[index1] == HUMAN)
				continue;//��һ�����ϴ���upload���������Ѿ��Զ��ϴ��ˣ����ﲻ�ÿ�������
			now_condition.upload(now_condition.start[index1], now_condition.start);
			if (now_condition.exist())//�ϴ�֮���鰶�ߵĶ����Ƿ񲢴�
			{
				if (start)
					start = false;
				
				re.build_record(now_condition.member[0], now_condition.member[1], true);
				record_array[record_num++] = re.record;
				solution_end(now_condition, step+1);
				now_condition.download(now_condition.start);
				if (record_num)
				{
					record_num--;
					record_array[record_num] = "��һ�в�Ӧ�ó���";
				}
			}
			else
				now_condition.download(now_condition.start);//����Ͻ��´���׼����һ�����
			
			
		}
	}
	
	if (record_num)
	{
		record_num--;
		record_array[record_num] = "��һ�в�Ӧ�ó���";
		//record_num--;
		//record_array[record_num] = "��һ�в�Ӧ�ó���";
	}
	return;
}

void solution_end(boat prior_condition, int step)
{
	boat now_condition = prior_condition;
	record_elem re;
	//����֮�����´���˵
	re.build_record(now_condition.member[0], now_condition.member[1], false);
	record_array[record_num++] = re.record;
	now_condition.download(now_condition.end);

	if (finish_check(now_condition))
	{
		system("cls");
		//print_solution();
		//system("pause");
		solution_builder();


		//record_array[record_num] = "��һ�в�Ӧ�ó���";
		//record_num--;
	}
	else if (!start && condition_already_exist(now_condition, step))
	{
		record_num--;
		record_array[record_num] = "��һ�в�Ӧ�ó���";
		//record_num--;
		//record_array[record_num] = "��һ�в�Ӧ�ó���";
		return;
	}
	else
	{
		add_condition_record(now_condition, step);
		for (int index1 = 0; index1 < 5; index1++)
		{
			//if (now_condition.end[index1] == 0)
				//continue;
			if (now_condition.end[index1] == HUMAN)
				continue;//��һ�����ϴ���upload���������Ѿ��Զ��ϴ��ˣ����ﲻ�ÿ�������
			now_condition.upload(now_condition.end[index1], now_condition.end);
			if (now_condition.exist())//�ϴ�֮���鰶�ߵĶ����Ƿ񲢴�
			{
				
				re.build_record(now_condition.member[0], now_condition.member[1], true);
				record_array[record_num++] = re.record;
				solution_start(now_condition, step + 1);
				now_condition.download(now_condition.end);
				if (record_num)
				{
					record_num--;
					record_array[record_num] = "��һ�в�Ӧ�ó���";
				}
			}
			else
				now_condition.download(now_condition.end);//����Ͻ��´���׼����һ�����
			
		}
	}

	if (record_num)
	{
		record_num--;
		record_array[record_num] = "��һ�в�Ӧ�ó���";
		//record_num--;
		//record_array[record_num] = "��һ�в�Ӧ�ó���";
	}
	return;
}

void initial_start()
{
	b.start[0] = HUMAN;
	b.start[1] = WOLF;
	b.start[2] = GOAT;
	b.start[3] = CABBAGE;
}


int main()
{
	boat s;
	int step = 0;
	int count = 1;
	//initial_start();
	//s = b;
	solution_start(s, step);
	
	for (int i = 0; i < solution_num; i++)
	{
		cout << "����" << count++ << endl;
		cout << solution_set[i].method << endl;
	}
	
	return 0;
}
#include <stdio.h>
#include <stdlib.h>



void qsort(void* base, size_t num, size_t width, int(__cdecl* compare)(const void*, const void*));
//base    :Ҫ�����Ԫ�ص�ַ
//num     :Ԫ�ظ���
//width   :ÿ��Ԫ���ֽڴ�С
//compare :�����Ƚ�����Ԫ�صĺ���
//			{
//				���� -->  ����  1
//				���� -->  ����  0
//				С�� -->  ����  -1
//			}


//void* ���͵�ָ��  ���Խ����κ����͵�ָ��
//void*             ���ܽ��н����ò���
//void*             ���ܽ���+-�����Ĳ���
//void*				���ܽ��бȽ�

int tmp_int(const void* num1, const void* num2)
{
	return *(int*)num1 - *(int*)num2;
}

struct stu
{
	char name[20];
	int age;
};

int tmp_float(const void* num1, const void* num2)
{
	//if (num1 > num2)
	//	return 1;
	//else if (num1 == num2)
	//	return 0;
	//else
	//	return -1;
	// 
	if (*(float*)num1 > *(float*)num2)
		return 1;
	else if (*(float*)num1 == *(float*)num2)
		return 0;
	else
		return -1;
}

int tmp_str_name(const void* e1, const void* e2)
{
	//��Ҫ����	stdlib.h
	//strcmp	���ڷ���	1
	//			���ڷ���	2
	//			С�ڷ���	-1
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}

void int_arr(int i)
{
	int sz = 0;
	int arr[] = { 1,1,4,5,1,4,1,9,1,9,8,1,0 };
	sz = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, sz, sizeof(arr[0]), tmp_int);
	for (; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

void float_arr(int i)
{
	int sz = 0;
	float arr[] = { 2.45, 1.45, 6.67 };
	sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, arr[0], tmp_float);
	for (i = 0; i < sz; i++)
	{
		printf("%f ", arr[i]);
	}
}

void struct_stu_name(int i)
{
	int sz = 0;
	struct stu s1[3] = { {"zhangsan",11}, {"lisi",19}, {"wangerdan",15} };
	sz = sizeof(s1) / sizeof(s1[1]);
	qsort(s1, sz, s1->name, tmp_str_name);
}


int main()
{
	int i = 0;
	//int_arr(i);
	//float_arr(i);
	struct_stu_name(i);
	return 0;
}



////������ -- ������Ԫ�ص�ַ  ||  ��������?
////&arr -- ������������ĵ�ַ
//
//int main()
//{
//	int i;
//	int arr[] = { 1,2,3 };
//	printf("%p\n", arr + 1);
//	printf("%p\n", &arr + 1);
//	printf("%p\n", &arr[1]);
//	printf("%p\n", arr);
//	return 0;
//}
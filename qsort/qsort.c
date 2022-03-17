#include <stdio.h>
#include <stdlib.h>

void bubble_sort(void* stardp, int sz, int width, int(*tmp)(const void* e1, const void* e2));
//在qsort的基础上自定义一个排序函数

void qsort(void* base, size_t num, size_t width, int(__cdecl* compare)(const void*, const void*));
//base    :要排序的元素地址
//num     :元素个数
//width   :每个元素字节大小
//compare :用来比较两个元素的函数
//			{
//				大于 -->  返回  1
//				等于 -->  返回  0
//				小于 -->  返回  -1
//			}


//void* 类型的指针  可以接受任何类型的指针
//void*             不能进行解引用操作
//void*             不能进行+-整数的操作
//void*				不能进行比较

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
	//需要引用	stdlib.h
	//strcmp	大于返回	1
	//			等于返回	2
	//			小于返回	-1
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}

void int_arr(int i)
{
	int sz = 0;
	int arr[] = { 1,1,4,5,1,4,1,9,1,9,8,1,0 };
	//sz = sizeof(arr) / sizeof(arr[0]);

	//qsort(arr, sz, sizeof(arr[0]), tmp_int);
	//int arr[] = { 1,1,4,5,1,4,1,9,1,9,8,1,0 };
	//int sz = 0;
	//int arr[] = { 3,2,1 };
	sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), tmp_int);
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

void swap(char* e1, char* e2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++);
	{
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
}

void bubble_sort(void* stardp, int sz, int width, int(*cmp)(void* e1, void* e2))
{
	int i = 0;
	//确定躺数
	for (; i < sz - 1; i++)
	{
		//确定一趟的多少
		int j = 0;
		for (; j < sz - i - 1; j++)
		{
			if (cmp((char*)stardp + j * width ,(char*)stardp + (j + 1) * width) > 0)
			{
				swap((char*)stardp + j * width, (char*)stardp + (1 + j) * width, width);
			}
		}
	}
}

int main()
{
	int i = 0;
	//int_arr(i);
	//float_arr(i);
	//struct_stu_name(i);
	int_arr(i);
	return 0;
}



////数组名 -- 代表首元素地址
////&arr -- 代表整个数组的地址
// sizeof(数组名)  --  数组名代表整个数组
//sizeof(&数组名)  --  &数组名代表整个数组
// 
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

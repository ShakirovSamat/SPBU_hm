#include <stdio.h>
#include <math.h>

int main()
{
	int lastNum = 2;

	printf("The program finds simple numbers < n\n");

	while (lastNum <= 2)
	{
		printf("N should b >= 2. Enter n = ");
		scanf_s("%d", &lastNum);
	}

	int simpleNums[100000] = {2};
	int curIndex = 0;
	for(int num = 3; num < lastNum; num += 2)
	{
		int isSimple = 1;
		for(int dIndex = 1; dIndex < curIndex; ++dIndex)
		{
			if((int)sqrt(num) < simpleNums[dIndex])
			{
				break;
			}
			if(num % simpleNums[dIndex] == 0)
			{
				isSimple = 0;
				break;
			}
		}
		if (isSimple){
			curIndex++;
			simpleNums[curIndex] = num;
		}
	}

	for(int i = 0; i <= curIndex; ++i)
	{
		printf("%d ", simpleNums[i]);
	}
	return 0;
}
#include <stdio.h>
//

int main(int argc, char **argv) 
{
	int low, high, mid, yesorno, contorno;
	low = 1;
	high = 100;
	contorno = 'y';
	printf("Welcome to the High Low game...\n");


	while (contorno == '\b' || contorno== 'y')
	{
		printf("Think of a number between 1 and 100 and press <enter>");
		getchar();

		//
		while(high > low)
		{
			mid = (low+high)/2;
			printf("Is it higher than %d? (y/n)\n", mid);
			yesorno = getchar();
			getchar(); 
			while(yesorno != 'y' && yesorno != 'n')
			{
				printf("Type y or n\n");
				printf("Is it higher than %d? (y/n)\n", mid);
				yesorno = getchar();
				getchar();
			}
			

			//
			if (yesorno == 'y')
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}

			//
			if(high == low)
			{
				printf("Is it higher than %d? (y/n)\n", low);
				yesorno = getchar();
				getchar();
				if(yesorno  == 'y')
				{
					low = low + 1;
					break;
				}
				
			}
		}


		printf("\n>>>>>> The number is %d\n\n", low);
		printf("Do you want to continue playing (y/n)?");
		low = 1;
		high = 100;
		contorno = getchar();
		getchar();
	}


printf("Thanks for playing!!!");
}





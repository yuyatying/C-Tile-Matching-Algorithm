#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void main() {
	srand(time(NULL));
	int N, M, candy_array[100][100],score=0,flag2=1;
	char c1[100], c2[100];
	printf("Enter field size seperated by a space(Max: 100*100)");
	//Check validity of input
	while (flag2 >= 0) {
		flag2 = 1;
		scanf_s("%s", c1, 100);
		scanf_s("%s", c2, 100);
		for (int i = 0; i < strlen(c1); i++) {
			if ((c1[i] < 48) || (c1[i] > 57))
				flag2=0;
		}
		for (int i = 0; i < strlen(c2); i++) {
			if ((c2[i] < 48) || (c2[i] > 57))
				flag2=0;
		}
		N = atoi(c1);
		M = atoi(c2);
		if (!(N<=100&&N>0)||!(M<=100&&M>0)) {
			flag2 = 0;
		}
		if (flag2 == 1)
			break;
		printf("Invalid! Please enter field size seperated by a space(Max: 100*100): ");
	}
	int i , k, dummy[100][100],rearrange[100][100],counter=0,flag=1;
	printf("  ");
	for (k = 0; k < M; k++)
		printf("%d",k + 1);
	printf("\n\n");
	for (i = 0; i < N; i++) {
		printf("%d ", i+1);
		for (k = 0; k < M; k++) {
			candy_array[i][k] = (rand() % 6) + 1;
			printf("%d", candy_array[i][k]);
		}
		printf("\n");
	}
	printf("\nRemoved Gem= %d\n", score);
	printf("Score= %d\n", score * 50);
	while (flag>=0) {
		for (i = 0; i < N; i++) {
			for (k = 0; k < M; k++) {
				dummy[i][k] = candy_array[i][k];
				rearrange[i][k] = -1;
			}
		}
		// Horizontal search 
		for (i = 0; i < N; i++) {
			for (int k = 0; k < M; k++) {
				if (k + 2 <= M - 1) {
					if (dummy[i][k] == dummy[i][k + 1] && dummy[i][k] == dummy[i][k + 2]) {
						candy_array[i][k] = -1;
					}
				}
				if (k - 2 >= 0) {
					if (dummy[i][k] == dummy[i][k - 1] && dummy[i][k] == dummy[i][k - 2]) {
						candy_array[i][k] = -1;
					}
				}
				if (k - 1 >= 0 && k + 1 <= M - 1) {
					if (dummy[i][k] == dummy[i][k - 1] && dummy[i][k] == dummy[i][k + 1]) {
						candy_array[i][k] = -1;
					}
				}
			}
		}
		//Vertical Search
		for (i = 0; i < N; i++) {
			for (int k = 0; k < M; k++) {
				if (i + 2 <= N - 1) {
					if (dummy[i][k] == dummy[i + 1][k] && dummy[i][k] == dummy[i + 2][k]) {
						candy_array[i][k] = -1;
					}
				}
				if (i - 2 >= 0) {
					if (dummy[i][k] == dummy[i - 1][k] && dummy[i][k] == dummy[i - 2][k]) {
						candy_array[i][k] = -1;
					}
				}
				if (i - 1 >= 0 && i + 1 <= N - 1) {
					if (dummy[i][k] == dummy[i - 1][k] && dummy[i][k] == dummy[i + 1][k]) {
						candy_array[i][k] = -1;
					}
				}
			}
		}
		//Score counting and print -1 array
		printf("\n");
		flag = 0;
		for (i = 0; i < N; i++) {
			for (k = 0; k < M; k++) {
				//printf("%d", candy_array[i][k]);
				if (candy_array[i][k] == -1) {
					score++;
					flag = 1;
				}
			}
		}
		if (flag == 1) {
			printf("'-1' labelled candy array:\n");
			printf("  ");
			for (k = 0; k < M; k++)
				printf("%d", k + 1);
			printf("\n\n");
			for (i = 0; i < N; i++) {
				printf("%d ", i + 1);
				for (k = 0; k < M; k++) {
					printf("%d", candy_array[i][k]);
				}
				printf("\n");
			}
			printf("\nRemoved Gem= %d\n", score);
			printf("Score= %d\n", score * 50);
		}
		if (flag == 0) {
			break;
		}
		counter = N - 1;
		//Clear Candy Chains
		for (k = 0; k < M; k++) {
			for (i = N - 1; i >= 0; i--) {
				if (candy_array[i][k] > 0) {
					rearrange[counter][k] = candy_array[i][k];
					counter--;
				}
			}
			counter = N - 1;
		}
		//Refill
		for (i = 0; i < N; i++) {
			for (k = 0; k < M; k++) {
				if (rearrange[i][k] == -1) {
					rearrange[i][k] = (rand() % 6) + 1;
				}
				candy_array[i][k] = rearrange[i][k];
			}
		}
		//Print New Array
		printf("\nUpdated Field:\n");
		printf("  ");
		for (k = 0; k < M; k++)
			printf("%d", k + 1);
		printf("\n\n");
		for (i = 0; i < N; i++) {
			printf("%d ", i + 1);
			for (k = 0; k < M; k++) {
				printf("%d", candy_array[i][k]);
			}
			printf("\n");
		}
		printf("\nRemoved Gem= %d\n", score);
		printf("Score= %d\n", score * 50);
	}
	printf("Choose the element to be swapped by typing x y\n");
	printf("x is the horizontal index, y is the vertical index\n");
	printf("Your input(x y): ");



	int x, y,D=0 ,ask = 0;
//Check validity of input
	flag2 = 1;
	while (flag2 >= 0) {
		flag2 = 1;
		scanf_s("%s", c1, 100);
		scanf_s("%s", c2, 100);
		for (int i = 0; i < strlen(c1); i++) {
			if ((c1[i] < 48) || (c1[i] > 57))
				flag2 = 0;
		}
		for (int i = 0; i < strlen(c2); i++) {
			if ((c2[i] < 48) || (c2[i] > 57))
				flag2 = 0;
		}
		x = atoi(c1);
		y = atoi(c2);
		if (!(x <= N && x>0) || !(y <= M && y>0)) {
			flag2 = 0;
		}
		if (flag2 == 1)
			break;
		printf("Invalid! Please input two integers seperated by a space!(x y): ");
	}

	//72=Up, 80=Down, 75=Left, 77=Right


	printf("Press arrow keys to swap place\n");
	D = getch();
	if (D != 72 && D != 75 && D != 80 && D != 77 && D!=224)
		printf("Please press valid arrow keys to swap place\n");
	while (D != 72 && D != 75 && D != 80 && D != 77) {
		if (D != 72 && D != 75 && D != 80 && D != 77 && D != 224)
			D = getch();
		if (D == 224)
			D = getch();
		if (x == 1 && D == 72) 
			D = -D;
		if (x == N && D == 80)
			D = -D;
		if (y == 1 && D == 75)
			D = -D;
		if (y == M && D == 77)
			D = -D;
		switch (D) {
			//Up
		case 72:
			printf("Arrow Pressed = Up");
			ask = candy_array[x - 1][y - 1];
			candy_array[x - 1][y - 1] = candy_array[x - 1 - 1][y - 1];
			candy_array[x - 1 - 1][y - 1] = ask;
			printf("\nUpdated Field:\n");
			printf("  ");
			for (k = 0; k < M; k++)
				printf("%d", k + 1);
			printf("\n\n");
			for (i = 0; i < N; i++) {
				printf("%d ", i + 1);
				for (k = 0; k < M; k++) {
					printf("%d", candy_array[i][k]);
				}
				printf("\n");
			}
			printf("\nRemoved Gem= %d\n", score);
			printf("Score= %d\n", score * 50);
			break;
			//Down
		case 80:
			printf("Arrow Pressed = Down");
			ask = candy_array[x - 1][y - 1];
			candy_array[x - 1][y - 1] = candy_array[x - 1 + 1][y - 1];
			candy_array[x - 1 + 1][y - 1] = ask;
			printf("\nUpdated Field:\n");
			printf("  ");
			for (k = 0; k < M; k++)
				printf("%d", k + 1);
			printf("\n\n");
			for (i = 0; i < N; i++) {
				printf("%d ", i + 1);
				for (k = 0; k < M; k++) {
					printf("%d", candy_array[i][k]);
				}
				printf("\n");
			}
			printf("\nRemoved Gem= %d\n", score);
			printf("Score= %d\n", score * 50);
			break;
			//Left
		case 75:
			printf("Arrow Pressed = Left");
			ask = candy_array[x - 1][y - 1];
			candy_array[x - 1][y - 1] = candy_array[x - 1][y - 1 - 1];
			candy_array[x - 1][y - 1 - 1] = ask;
			printf("\nUpdated Field:\n");
			printf("  ");
			for (k = 0; k < M; k++)
				printf("%d", k + 1);
			printf("\n\n");
			for (i = 0; i < N; i++) {
				printf("%d ", i + 1);
				for (k = 0; k < M; k++) {
					printf("%d", candy_array[i][k]);
				}
				printf("\n");
			}
			printf("\nRemoved Gem= %d\n", score);
			printf("Score= %d\n", score * 50);
			break;
			//Right
		case 77:
			printf("Arrow Pressed = Right");
			ask = candy_array[x - 1][y - 1];
			candy_array[x - 1][y - 1] = candy_array[x - 1][y - 1 + 1];
			candy_array[x - 1][y - 1 + 1] = ask;
			printf("\nUpdated Field:\n");
			printf("  ");
			for (k = 0; k < M; k++)
				printf("%d", k + 1);
			printf("\n\n");
			for (i = 0; i < N; i++) {
				printf("%d ", i + 1);
				for (k = 0; k < M; k++) {
					printf("%d", candy_array[i][k]);
				}
				printf("\n");
			}
			printf("\nRemoved Gem= %d\n", score);
			printf("Score= %d\n", score * 50);
			break;
		default:
			printf("Please press valid arrow keys to swap place!\n");
		}
	}
	flag = 0;
	while (flag >= 0) {
		for (i = 0; i < N; i++) {
			for (k = 0; k < M; k++) {
				dummy[i][k] = candy_array[i][k];
				rearrange[i][k] = -1;
			}
		}
		// Horizontal search 
		for (i = 0; i < N; i++) {
			for (int k = 0; k < M; k++) {
				if (k + 2 <= M - 1) {
					if (dummy[i][k] == dummy[i][k + 1] && dummy[i][k] == dummy[i][k + 2]) {
						candy_array[i][k] = -1;
					}
				}
				if (k - 2 >= 0) {
					if (dummy[i][k] == dummy[i][k - 1] && dummy[i][k] == dummy[i][k - 2]) {
						candy_array[i][k] = -1;
					}
				}
				if (k - 1 >= 0 && k + 1 <= M - 1) {
					if (dummy[i][k] == dummy[i][k - 1] && dummy[i][k] == dummy[i][k + 1]) {
						candy_array[i][k] = -1;
					}
				}
			}
		}
		//Vertical Search
		for (i = 0; i < N; i++) {
			for (int k = 0; k < M; k++) {
				if (i + 2 <= N - 1) {
					if (dummy[i][k] == dummy[i + 1][k] && dummy[i][k] == dummy[i + 2][k]) {
						candy_array[i][k] = -1;
					}
				}
				if (i - 2 >= 0) {
					if (dummy[i][k] == dummy[i - 1][k] && dummy[i][k] == dummy[i - 2][k]) {
						candy_array[i][k] = -1;
					}
				}
				if (i - 1 >= 0 && i + 1 <= N - 1) {
					if (dummy[i][k] == dummy[i - 1][k] && dummy[i][k] == dummy[i + 1][k]) {
						candy_array[i][k] = -1;
					}
				}
			}
		}
		//Score counting and print -1 array
		printf("\n");
		flag = 0;
		for (i = 0; i < N; i++) {
			for (k = 0; k < M; k++) {
				//printf("%d", candy_array[i][k]);
				if (candy_array[i][k] == -1) {
					score++;
					flag = 1;
				}
			}
		}
		if (flag == 1) {
			printf("'-1' labelled candy array:\n");
			printf("  ");
			for (k = 0; k < M; k++)
				printf("%d", k + 1);
			printf("\n\n");
			for (i = 0; i < N; i++) {
				printf("%d ", i + 1);
				for (k = 0; k < M; k++) {
					printf("%d", candy_array[i][k]);
				}
				printf("\n");
			}
			printf("\nRemoved Gem= %d\n", score);
			printf("Score= %d\n", score * 50);
		}
		if (flag == 0) {
			break;
		}
		counter = N - 1;
		//Clear Candy Chains
		for (k = 0; k < M; k++) {
			for (i = N - 1; i >= 0; i--) {
				if (candy_array[i][k] > 0) {
					rearrange[counter][k] = candy_array[i][k];
					counter--;
				}
			}
			counter = N - 1;
		}
		//Refill
		for (i = 0; i < N; i++) {
			for (k = 0; k < M; k++) {
				if (rearrange[i][k] == -1) {
					rearrange[i][k] = (rand() % 6) + 1;
				}
				candy_array[i][k] = rearrange[i][k];
			}
		}
		//Print New Array
		printf("\nUpdated Field:\n");
		printf("  ");
		for (k = 0; k < M; k++)
			printf("%d", k + 1);
		printf("\n\n");
		for (i = 0; i < N; i++) {
			printf("%d ", i + 1);
			for (k = 0; k < M; k++) {
				printf("%d", candy_array[i][k]);
			}
			printf("\n");
		}
		printf("\nRemoved Gem= %d\n", score);
		printf("Score= %d\n", score * 50);
	}
	system("pause");
}
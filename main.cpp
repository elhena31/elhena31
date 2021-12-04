#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <ctime>

#include "Snake.h"
#include "Food.hvv"

#define WIDTH 50
#define HEIGHT 25


using namespace std;

Snake snake({WIDTH/2, HEIGHT/2}, 1); // creacion del objeto 'snake' proveniente de la clase 'Snake'

Food food;  // creacion del objeto 'food' proveniente de la clase 'Food'

int score; // declaracion de un entero llamado score

void board(){  // llamado al board
	
	COORD snake_pos = snake.get_pos(); //obtenemos la posicion de snake y la guardamos en snake_pos
	COORD food_pos = food.get_pos();		// obtenemos la posicion de food y lo guardamos en food_pos
	
	vector<COORD> snake_body = snake.get_body();  // obtenemos el tamaños o 'body' de 'snake'
	
	cout<<"SCORE : " <<score << "\n\n"; 
	
	for (int i=0; i < HEIGHT; i++) 	//ciclo for para 
	{								//llenae con # desde 0 hasta height=25
		cout<<"\t\t\t#";			//
		for(int j = 0; j < WIDTH - 2; j++) 			//ciclo for para llenar
		{											//con 3 la columna 0 y la columna 24 o
			if(i == 0 || i == HEIGHT-1)	cout<<"8";	// Heigth - 1
			
			else if(i == snake_pos.Y && j + 1 == snake_pos.X) cout<<'0'; 
			else if(i == food_pos.Y && j + 1 == food_pos.X) cout<<'v';
		
			else
			{
				bool isBodyPart = false;
				for(int k = 0; k < snake_body.size()-1; k++)
				{
					if(i == snake_body[k].Y && j+1 == snake_body[k].X)
					{
						cout<< 'n';
						isBodyPart = true;
						break;
					}
				}
				
				if(! isBodyPart) cout<<' ';
			}
		}
		cout<<"#\n";
	}
}

int main() 
{
	srand(time(NULL));
	
	food.gen_food(); // llamado al metodo generar comida
	
	bool game_over = false;

	while(!game_over)  // mientras NO sea game over
	{
		board();

		if(kbhit())  // if Keyboard is hit
		{
			switch(getch())	
			{
				case 'w' : snake.change_dir('u');break;
				case 'a' : snake.change_dir('l');break;
				case 's' : snake.change_dir('d');break;
				case 'd' : snake.change_dir('r');break;
			}	
		}
		
		if(snake.eaten(food.get_pos()))
		{
			food.gen_food();
			snake.grow();
			score++;
		}
		if(snake.collided()) game_over = true;
		
		snake.move_Snake();
		
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
	}
	board();
	
	return 0;
}

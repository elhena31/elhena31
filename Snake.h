#ifndef SNAKE_H
#define SNAKE_H

#define WIDTH 50
#define HEIGHT 25

#include <vector>
#include <windows.h>

using namespace std;

class Snake
{	
	//   Atributos
	private: 
		COORD pos;     // definimos la pos como atributo a la cual le pertenecen unas coordenadas x, y
		int len;		//  definimos la variable de tipo entero longitud = len
		int vel;		//  definimos la variable de tipo entero velocidad = vel
		char direction; ////  definimos la variable de tipo caracter direccion	
		vector<COORD> body; //  definimos el vector que almacenara el cuerpo de coordenadas
	// Metodos			
	public:
		Snake(COORD pos, int vel); // Constructor de la clase Snake
		void grow();               //  establecemos la funcion grow()
		void change_dir(char dir); //  establecemos la funcion change_dir()
		void move_Snake();			// establecemos la funcion move_Snake()
		
		vector<COORD> get_body(); // funcion getter 
				
		bool collided();
		bool eaten(COORD food_pos);		
		COORD get_pos();
};

#endif
		
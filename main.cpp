#include "Executive.h"
#include <time.h>

int main(int argc, char* argv[])
{

	if(argc<1)
	{
		std::cout<<"Incorrect number of parameters!\n";
	}
	else
	{
		int maxMines=0;

		int row=0;
		int col=0;
		int mines=0;


		std::cout<<"Enter the number of rows you would like: ";
		std::cin>>row;

/*--------------------------------------------------------------------rows failbit------------------------------------------------------------------*/

		while(std::cin.fail()) //failbit
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout<<"Please enter a number!\n Row:";
			std::cin>>row;
			std::cout<<endl;
		}			//end failbit




		while(row<2|| row>40)   //checks to see if row is in bounds
		{
			std::cout<<"The number of rows you provided is out of bounds. The lower bound is 2 and the upper bound is 4.\n Enter # of rows: ";
			std::cin>>row;



			while(std::cin.fail()) //failbit
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout<<"Please enter a number!\n Row:";
				std::cin>>row;
				std::cout<<endl;
			}			//end failbit




		}



		std::cout<<"Enter the number of columns you would like: ";
		std::cin>>col;

/*--------------------------------------------------------------------columns failbit------------------------------------------------------------------*/
		while(std::cin.fail()) //failbit
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout<<"Please enter a number!\n Row:";
			std::cin>>row;
			std::cout<<endl;
		}			//end failbit




		while(col<2|| col>40)   //checks to see if row is in bounds
		{
			std::cout<<"The number of columns you provided is out of bounds. The lower bound is 2 and the upper bound is 4.\n Enter # of columns: ";
			std::cin>>row;



			while(std::cin.fail()) //failbit
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout<<"Please enter a number!\n Row:";
				std::cin>>row;
				std::cout<<endl;
			}			//end failbit




		}


	maxMines=row*col;

	std::cout<<"Enter the number of mines you would like: ";
	std::cin>>mines;

/*--------------------------------------------------------------------mines failbit------------------------------------------------------------------*/
	while(std::cin.fail()) //failbit
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout<<"Please enter a number!\n";
		std::cin>>mines;
		std::cout<<endl;
	}			//end failbit




	while(mines<=0|| mines>maxMines-1)   //checks to see if row is in bounds
	{
		std::cout<<"The number of mines you provided is out of bounds. The lower bound is 1 and the upper bound is "<<maxMines<<"\n Enter # of mines: ";
		std::cin>>mines;



		while(std::cin.fail()) //failbit
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout<<"Please enter a number!\n Row:";
			std::cin>>row;
			std::cout<<endl;
      // std::cout<<mi  nes;
		}			//end failbit




	}



	Executive exec(row,col,mines);
	exec.run();

	}


return(0);
}
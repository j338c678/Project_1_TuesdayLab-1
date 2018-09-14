#include "Executive.h"
using namespace std;


Executive::Executive()
{
	m_row=0;
	m_col=0;
	m_mines=0;
}


Executive::Executive(std::string row, std::string col, std::string numMines)
{


	m_row=std::stoi(row);
	m_col=std::stoi(col);
	m_mines=std::stoi(numMines);


}


void Executive::run()
{
	// int m_row=0;
	// int m_col=0;
	// int m_mines=0;
	std::cout<<"Welcome to Minesweeper!\n";
	// cout<<"input the row\n";
	// cin>>m_row;
	// cout<<"input the col\n";
	// cin>>m_col;
	// cout<<"input the mines\n";
	// cin>>m_mines;
	Minesweeper sweep(m_row, m_col, m_mines);
	int row=0;
	int col=0;
	std::string choice=" ";
	while(true)
	{
		//std::cout<<"Would you like to pick a spot or flag a spot, or exit?  (pick/flag/exit)\n";
		sweep.print();
		std::cout<<"1)R(Reveal)\n2)F(Flag)\n3)U(Unflag)\n4)E(Exit)\nPlease make your selection:";
		std::cin>>choice;
		int length=choice.size();
		for(int i=0;i<length;i++)
		{
			std::tolower(choice[i]);
		}
		if(choice=="E")
		{
			break;
		}
		else if(choice=="R")
		{
			std::cout<<"Please enter your row:";
			std::cin>>row;
			std::cout<<"Please enter your column:";
			std::cin>>col;
			if(sweep.Revealing(row,col)==false)
			{
				sweep.print2();
				std::cout<<"Sorry.You lose!";
				// sweep.print2();
				break;
			}
		}
		else if(choice=="F")
		{
			std::cout<<"Please enter your row:";
			std::cin>>row;
			std::cout<<"Please enter your column:";
			std::cin>>col;
			if(sweep.Marking(row,col,1))
			{
				std::cout<<"Congratulations!You win the game!\n";
				break;
			}
		}
		else if(choice=="U")
		{
			std::cout<<"Please enter your row:";
			std::cin>>row;
			std::cout<<"Please enter your column:";
			std::cin>>col;
			sweep.Marking(row,col,2);
		}
	}
}
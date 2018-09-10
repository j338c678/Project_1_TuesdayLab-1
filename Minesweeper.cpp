#include"Minesweeper.h"
#include<string>
using namespace std;

void Minesweeper::print()
{
  cout<<" ";
  for(int k=1;k<=m_row; k++)
  {
    cout<<k;
  }
  cout<<endl;
  for(int i=1; i<=m_row; i++)
  cout<<i;
  {
    for(int j=1; j<=m_col; j++)
    {
      cout<<Uboard[i][j];
    }
    cout<<"\n";
  }
}


void Minesweeper::setMines(int mines)
{

  int count; //use to set the number of mines
  while(count < mines)
  {
    for(int i =0; i<m_row; i++)
    {
      for(int j=0; j<m_col; j++)
        {
          int tempRow = rand() % (m_row-1);
          int tempCol = rand() % (m_col-1);
          //set the mine is the block is blank, otherwise keep looping
          if(Bboard[tempRow][tempCol] == "")
          {
            Bboard[tempRow][tempCol] = "Mine";
            count++;
          }
        }
        //keep looping if the number of mine is not enough
    }
}

Minesweeper:: Minesweeper(int Row, int Col, int NumOfMines)
{
  m_row = Row;
  m_col = Col;
  num = NumOfMines;
  //remaining = num;

  Uboard  = new string* [m_row];
  for (int i = 0; i < Row; i++)
  {
    //Uboard[i] = new string [m_col];
      Uboard[i] = new string [m_col];
  }

  Bboard = new string* [m_row];
  for (int i = 0; i < row; i++)
  {
      Bboard[i] = new string [m_col];

  }

  setMines(NumOfMines);
}

Minesweeper:: ~Minesweeper()
{
  for (int i = 0; i < m_row; i++)
  {
    delete[] Uboard[i];
  }
  delete[] Uboard;

  for (int i = 0; i < m_row; i++)
  {
    delete[] Bboard[i];
  }
  delete[] Bboard;
}


bool Minesweeper::Marking(int Row, int Col, int option)
{
  if(option==1 && Uboard[Row][Col]==" ")
  {
    Uboard[Row][Col] = "Flag";
    if(Bboard[Row][Col]=="Mine")
    {
      NumOfFlag++;
      if(NumOfFlag==m_mines)
      {
      return(true);//Condition1:set all the flags on the correct mines.
      }
      else
      {
      return(false);// Condetion2:set one flag on the correct position.
      }
    }
    else
    {
      return(false);//Condition3:set one flag on the wrong position.
    }
  }
  else//unflag function
  {
    Uboard[Row][Col] = " ";
    if(Bboard[Row][Col]=="Mine")
    {
      NumOfFlag--;
    }
    return(false);
  }
}

bool Minesweeper::Revealing(int Row, int Col)
{
  if(Bboard[Row][Col]!="Mine")
  {
    if(Row < m_row && Col < m_col && Row >= 0 && Col >= 0)
    {
      RecCheck(Row, Col);
      return(true);
    }
  }
  else
  {
    return(false);
  }
}

{
  void Minesweeper::RecCheck(int Row, int Col)
  if(check(Row,Col)==0)
  {
    Uboard[Row][Col]=="[]";
    RecCheck(Row-1,Col-1);
    RecCheck(Row+1,Col+1);
    RecCheck(Row+1,Col-1);
    RecCheck(Row-1,Col+1);
    RecCheck(Row,Col+1);
    RecCheck(Row+1,Col);
    RecCheck(Row,Col-1);
    RecCheck(Row-1,Col);
  }
  else
  {
    Uboard[Row][Col]=Check(Row,Col);
  }
}


int Minesweeper::Check(int Row, int Col)
{
  int count=0;
  for(int i=0;i<Row;i++)
  {
    for(int j=0; j<Col; j++)
    {
      if(Bboard[i][j+1])
      {
        count++;
      }
      if(Bboard[i][j-1])
      {
        count++;
      }
      if(Bboard[i+1][j])
      {
        count++;
      }
      if(Bboard[i-1][j])
      {
        count++;
      }
      if(Bboard[i+1][j+1])
      {
        count++;
      }
      if(Bboard[i+1][i-1])
      {
        count++;
      }
      if(Bboard[i-1][j+1])
      {
        count++;
      }
      if(Bboard[i-1][j-1])
      {
        count++;
      }
    }
  }
  return(count);
}

// char Minesweeper::getLetter()
// {
//
// }

/**
 * TermPong v1
 * 
 * File: coordinate.cpp
 * 
 * Description:
 *  A clone of the pong game using ncuses libay in C++
 * 
 * Author: 
 *  Saurabh Singh (saurabh.s99100@gmail.com)
 *
 * MIT License
 * 
 * Copyright (c) 2021 Saurabh Singh
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * 
 */

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#include "coordinate.h"

// Constant definitions
const unsigned int mSec = 1000;     // 1 msec = 1000us
const unsigned int Sec = 1000000;   // 1 sec  = 1000000us

const char ballChar = '@';          // character used for displaying ball
const char batChar = '=';           // character used for displaying bat
const int batLen = 8;               // length of bat (ensure even number)
const int scoreIncrementAmount = 5; // value to increment score with

int main()
{ 
    coordinate winLim(80, 26);
    coordinate scoreLoc(30, 0);

    const int frameLim = 10;    // move ball after every "frameLim" frames

    // Runtime variables
    unsigned int score = 0;
    int xVelocity = 1;
    int yVelocity = 1;

    int frameCount = 0;

    bool gameOver = false;
    bool paused = false;

    coordinate ballLoc(winLim.getX()/2, winLim.getY()/2);
    int batLoc = winLim.getX()/2;

    // Game Setup
    initscr();                  // initialize ncurses mode
    cbreak();                   // disable getch() buffering
    noecho();                   // disable getch() echo
    nodelay(stdscr, TRUE);      // disable getch() waiting for keypress
    curs_set(0);                // Hide cursor

    // Print splashSceen
    wmove(stdscr, 10-2, 37-36); wprintw(stdscr, " //////  //////  //////   //    //   /////     ///    //    //   /////  ");
    wmove(stdscr, 10-1, 37-36); wprintw(stdscr, "   //    //      //   //  ///  ///   //  //  //   //  ///   //  //      ");
    wmove(stdscr, 10+0, 37-36); wprintw(stdscr, "   //    ////    /////    // // //   /////   //   //  // // //  // //// ");
    wmove(stdscr, 10+1, 37-36); wprintw(stdscr, "   //    //      //  //   //    //   //      //   //  //   ///  //   // ");
    wmove(stdscr, 10+2, 37-36); wprintw(stdscr, "   //    //////  //   //  //    //   //        ///    //    //   /////  ");

    wmove(stdscr, 10+5, 37-36); wprintw(stdscr, "   By          : Saurabh Singh (saurabh.s99100@gmail.com)   ");
    wmove(stdscr, 10+6, 37-36); wprintw(stdscr, "   Instructions: Move the bat left and right with keys 'a' and 'd'");
    wmove(stdscr, 10+7, 37-36); wprintw(stdscr, "                 Press 'p' to pause & 'q' to quit");
    
    wrefresh(stdscr);
    usleep(1 * Sec);
    
    wmove(stdscr, 10+9, 37-36); wprintw(stdscr, "                 === READY ===");
    wrefresh(stdscr);
    usleep(1 * Sec);
    wmove(stdscr, 10+9, 37-36); wprintw(stdscr, "                              === SET ===");
    wrefresh(stdscr);
    usleep(1 * Sec);
    wmove(stdscr, 10+9, 37-36); wprintw(stdscr, "                                         === GO! ===");
    wrefresh(stdscr);
    usleep(1 * Sec);
    wclear(stdscr);
    
    // Print header
    wmove(stdscr, 0, 1); wprintw(stdscr, "TermPong v1");
    wmove(stdscr, 0, 22); wprintw(stdscr, "Score : ");

    WINDOW * gameWin = newwin(winLim.getY(), winLim.getX(), 1, 1);
    wrefresh(stdscr);
    wrefresh(gameWin);

    while(!gameOver)
    {
        // read input
        char inchar = getch();
        if(inchar == 'q')
            break;
        if(inchar == 'p')
            paused = !paused;

        if(!paused)
        {
            if(frameCount == frameLim)
            {
                // calculate new ball location
                ballLoc.setX(ballLoc.getX()+xVelocity);
                ballLoc.setY(ballLoc.getY()+yVelocity);

                // Bounce ball
                if(ballLoc.getX() == 1)                     // left boundry
                {
                    xVelocity = -xVelocity;
                }
                else if(ballLoc.getX() == winLim.getX()-2)  // right boundry
                {
                    xVelocity = -xVelocity;
                }
                else if(ballLoc.getY() == 1)                // top boundry
                {
                    yVelocity = -yVelocity;
                }
                else if(ballLoc.getY() == winLim.getY()-3)
                {
                    if(ballLoc.getX() >= batLoc && ballLoc.getX() <= batLoc + batLen)
                    {
                        yVelocity = -yVelocity; // Bounce
                        score += scoreIncrementAmount;
                    }
                }
                else if(ballLoc.getY() == winLim.getY()-2)  // bottom boundry
                {
                    gameOver = true;
                }
                frameCount = 0;
            }
            else
            {
                frameCount++;
            }

            // calculate new bat location
            if(inchar == 'a')
            {
                if(batLoc != 1)
                    batLoc--;
            }
            else if(inchar == 'd')
            { 
                if(batLoc + batLen - 1 != winLim.getX()-2)
                    batLoc++;
            }

            // clear gameWin
            wclear(gameWin);
            box(gameWin, 0, 0);
            
            // print ball
            wmove(gameWin, ballLoc.getY(), ballLoc.getX()); 
            wprintw(gameWin, "%c", ballChar);

            wmove(gameWin, winLim.getY()-2, batLoc); 

            // print Bat 
            for(int i = 0; i < batLen; i++)
            { 
                wprintw(gameWin, "%c", batChar);
            }

            // print score
            wmove(stdscr, scoreLoc.getY(), scoreLoc.getX()); wprintw(stdscr, "%d", score);


            // refresh screen
            wrefresh(stdscr);
            wrefresh(gameWin);
        }
        
        if(paused)
        {
            wmove(stdscr, scoreLoc.getY(), scoreLoc.getX()+10); wprintw(stdscr, "PAUSED");
        }
        else
        {
            wmove(stdscr, scoreLoc.getY(), scoreLoc.getX()+10); wprintw(stdscr, "      ");
        }

        // loop delay
        //usleep(400 * mSec);
        
        usleep(10 * mSec);
    }

    if(gameOver)
    {
        WINDOW * gameOverScreen = newwin(4, 30, winLim.getY()/2 - 2, winLim.getX()/2 - 15);
        box(gameOverScreen, 0, 0);

        wmove(gameOverScreen, 1, 10); wprintw(gameOverScreen, "GAME  OVER");
        wmove(gameOverScreen, 2, 10); wprintw(gameOverScreen, "Score: ");
        wmove(gameOverScreen, 2, 17); wprintw(gameOverScreen, "%d", score);
        wrefresh(gameOverScreen);
        usleep(3*Sec);
    }
    endwin();
}

/*
 * constants.h
 *
 *  Created on: Mar 22, 2023
 *      Author: potts
 */

#ifndef INCLUDES_CONSTANTS_H_
#define INCLUDES_CONSTANTS_H_

#define INSTRUCTION_SIZE 8

#define SUCCESS 0

#define STALL 0  // {0,0,0};
#define RLEFT 1  // {0,0,1};
#define RRIGHT 2  // {0,1,0};
#define REVERSE 3  // {0,1,1};
#define FLEFT 6  // {1,1,0};
#define FRIGHT 5  // {1,0,1};
#define FORWARD 7  // {1,1,1};

const int UNDEFINED = -1;

#endif /* INCLUDES_CONSTANTS_H_ */

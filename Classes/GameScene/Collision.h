#ifndef __PROJ_COLLISION_H_
#define __PROJ_COLLISION_H_

enum Collision {
	PLAYER = 1,
	WALL =  1 << 1,
	ROCK = 1 << 2,
	CRYSTAL = 1 << 3,
	FOAM = 1 <<4
};

#endif // !__

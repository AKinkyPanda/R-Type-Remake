// add your external includes to this file instead of to individual .cpp files

#define SCRWIDTH		  384 //1280 //1280 //8640 //5764 //2880 //800
#define SCRHEIGHT		  192 //768 //576 //384//192
#define SCRSCALE          4
#define SIZE_SCALE_HEIGHT 3
#define SIZE_SCALE_WIDTH  1

//#define FULLSCREEN
// #define ADVANCEDGL	// faster if your system supports it

#include <cinttypes>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <cstdio>

extern "C"
{
#include "glew.h" 
}
#include "gl.h"
#include "wglext.h"

#include "SDL.h"

#include "FreeImage.h"
#include "template.h"
#include "surface.h"
#include "TerrainData.h"
#include "Terrain.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "BulletHandler.h"
#include "BackgroundCollision.h"
#include "Enemy.h"
#include "EnemyShipRed.h"
#include "AABB.h"
#include "Circle.h"
#include "Collision.h"
#include "CollisionHandler.h"
#include "EnemyManager.h"
#include "Animation.h"
#include "Cell.h"
#include "Grid.h"
#include "BaseObject.h"
#include "EnemyBulletRed.h"
#include "EnemyBulletRedManager.h"
#include "GameState.h"
#include "EnemyShipYellow.h"

//SIMD Intrinsics headers.
//#include "emmintrin.h"
//#include "immintrin.h"

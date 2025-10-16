#pragma once

constexpr int numEnemyBulletsRed = 3;

namespace Tmpl8 {
    class EnemyBulletRedManager :
        public EnemyBulletRed
    {
        int bulletCnt = 0;

        EnemyBulletRed* enemyBulletsRed[numEnemyBulletsRed * numEnemyShipRed];
    public:
        EnemyBulletRedManager();

        void Update(float deltaTime, float screenX, Player& player, EnemyShipRed* enemyShipsRed[]);
        void Fired(Player& player, EnemyShipRed* enemyShipsRed[]);
        void Draw(Surface* screen, float deltaTime, float screenX);

        EnemyBulletRed** GetEnemyBulletRed();
    };
}


#pragma once

namespace Tmpl8 {
    class EnemyShipYellow :
        public Enemy
    {
		float enemyPosX = 0;
		float enemyPosY = 0;

		float startY = 90;
		float startX = 0;

		float enemyW = 33;
		float enemyH = 24;

		const float speed = 0.1f;

		const float frameSpeed = 3.5f;
		const int numFrames = 3;

		float radius = 16;

		Circle enemyCircle = Circle(radius, enemyPosX, enemyPosY);

    public:
        EnemyShipYellow();
		EnemyShipYellow(float posX, float posY, float width, float height);

        enum State{SPAWNING, MOVING_UP, MOVING_DOWN};
		State state = SPAWNING;

        void Update(float deltaTime, float screenX);
        void Draw(Surface* screen, float deltaTime, float screenX);

		void Spawn(float screenX);
		void MoveUp(float deltaTime, float screenX);
		void MoveDown(float deltaTime, float screenX);

		float GetEnemyPosX() const;
		float GetEnemyPosY() const;
		float GetEnemyWidth() const;
		float GetEnemyHeight() const;

		Circle GetEnemyShipYellowCircle() const;
    };
}


#ifndef _GAMEOBJECTMANAGER_H
#define _GAMEOBJECTMANAGER_H
#include <vector>
#include "Player.h"
#include "GameObject.h"

class GameObjectManager {

public:
	GameObjectManager();
	~GameObjectManager();

	void update(float dt);
	void addGameObject(GameObject* gameObject);
	void constructPlayerBroadPhaseBox();

	const std::vector<GameObject*>& getGameObjects() const;

private:
	void handlePlayerCollisionAgainstMap(float dt, GameObject* object, glm::vec3& newVel, bool& hasCollided);

private:
	std::vector<GameObject*> m_gameObjects;
	Player* m_player;
	AABB* m_broadPhaseBox;
};

#endif

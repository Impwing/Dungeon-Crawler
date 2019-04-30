#ifndef _ROOM_H
#define _ROOM_H
#include "GameObject.h"
#include <AI/GridSystem.h>

class Room : public GameObject
{
public:
	Room(Mesh* mesh, Type type, const glm::vec3& position = glm::vec3(0));
	~Room();

	void update(float dt);
	GridSystem* getGrid() const;

private:

	GridSystem* m_gridsystem;
	Type m_type;
};


#endif

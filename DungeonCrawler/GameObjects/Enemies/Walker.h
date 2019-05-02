#pragma once
#ifndef _WALKER_H
#define _WALKER_H
#include <GameObjects/Room.h>
#include <AI/AStar.h>

class Walker : public GameObject {
public:
	Walker(Mesh* mesh, Type type, Room* room, const glm::vec3& position);
	~Walker();
	void update(float dt);

	void hitPlayer();
	void hit(const HitDescription& desc);
	Type getType();
	float getDamage()const;
	float getDistanceToPlayer() const;
	void amIDead();
	bool getAliveStatus()const;

private:
	void calculatePath(float dt);
	void moveToTarget(float dt);
private:
	float m_health;
	float m_speed;
	float m_damage;
	bool m_isPlayerClose;
	Type m_type;
	bool m_amIAlive;

	float m_AStarTimer;
	Room* m_room;
	AStar* m_Astar;
	std::vector<Node> m_path;
};

#endif // !_WALKER_H

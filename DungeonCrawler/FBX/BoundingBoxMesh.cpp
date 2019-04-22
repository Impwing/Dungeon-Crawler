#include "BoundingBoxMesh.h"

BoundingBoxMesh::BoundingBoxMesh()
{
	m_vertexCount = 8; //will always be 8 uniqe vertices
	m_collision = 0;
	m_isStatic = 0;

	initiateArrays();
}

BoundingBoxMesh::~BoundingBoxMesh()
{
}

void BoundingBoxMesh::CheckMesh()
{
	printf("Bounding box function working");
}

void BoundingBoxMesh::PrepareForNewMesh()
{
	m_vertexCount = 8;
	m_collision = 0;
	m_isStatic = 0;

	initiateArrays();
}

void BoundingBoxMesh::initiateArrays()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++)
			m_controlPoints[j][i] = 0;
	}
}
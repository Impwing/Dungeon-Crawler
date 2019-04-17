#include "MeshData2.h"

MeshData2::MeshData2()
{
	m_vertexCount = 0;

	m_currentControlPoint = 0;
	m_currentControlPointIndex = 0;
	m_currentUVCoordinate = 0;
	m_currentUVIndex = 0;
	m_currentNormalCoordinate = 0;

	m_collision = 0;
	m_isStatic = 0;

	m_nrOfPolygons = 0;
	m_nrOfVerticesPerPolygon = 0;

	initiateArrays();
}

MeshData2::~MeshData2()
{

}

void MeshData2::initiateArrays()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 3; j++)
			m_controlPoints[j][i] = 0.f;
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 2; j++)
			m_UVCoordinates[j][i] = 0.f;
	}

	for (int i = 0; i < 100; i++)
	{
		m_controlPointIndexArr[i] = 0;
		m_UVCoordinateIndexArr[i] = 0;
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 3; j++)
			m_normalCoordinateArr[j][i] = 0.f;
	}
}

void MeshData2::AddControlPoint(FbxVector4 controlPoint)
{
	float lx = controlPoint.mData[0];
	float ly = controlPoint.mData[1];
	float lz = controlPoint.mData[2];

	m_controlPoints[0][m_currentControlPoint] = lx;
	m_controlPoints[1][m_currentControlPoint] = ly;
	m_controlPoints[2][m_currentControlPoint] = lz;

	m_currentControlPoint++;
}

void MeshData2::AddIndexPoint(int index)
{
	m_controlPointIndexArr[m_currentControlPointIndex] = index;
	m_currentControlPointIndex++;
}

void MeshData2::AddUVCoordinate(FbxVector2 uVCoordinate)
{
	float lx = uVCoordinate.mData[0];
	float ly = uVCoordinate.mData[1];

	m_UVCoordinates[0][m_currentUVCoordinate] = lx;
	m_UVCoordinates[1][m_currentUVCoordinate] = ly;

	m_currentUVCoordinate++;
}

void MeshData2::AddUVIndex(int index)
{
	m_UVCoordinateIndexArr[m_currentUVIndex] = index; //CORRECT
	m_currentUVIndex++;
}

void MeshData2::AddNormalCoordinate(FbxVector4 normalCoordinate)
{
	float lx = normalCoordinate.mData[0];
	float ly = normalCoordinate.mData[1];
	float lz = normalCoordinate.mData[2];
	
	m_normalCoordinateArr[0][m_currentNormalCoordinate] = lx;
	m_normalCoordinateArr[1][m_currentNormalCoordinate] = ly;
	m_normalCoordinateArr[2][m_currentNormalCoordinate] = lz;

	m_currentNormalCoordinate++;
}

void MeshData2::increaseVertexCount()
{
	m_vertexCount++;
}

void MeshData2::CheckMesh()
{
	//Only works for triangulated Meshes
	for (int i = 0; i < m_nrOfPolygons; i++)
	{
		printf("Polygon %i:\n", i);
		if (m_nrOfVerticesPerPolygon == 3)
		{
			for (int j = 0; j < m_nrOfVerticesPerPolygon; j++) //Per Vertex Stuff
			{
				printf("Vertex %i:\n", j);
				//Position
				//Store currentPlaceInVerticeIndexArr if load more than 1 mesh, needs to be added for other start location
				int lCurrentVertex = (m_nrOfVerticesPerPolygon * i) + j;
				printf("Position: %.2f %.2f %.2f\n",
					m_controlPoints[0][m_controlPointIndexArr[lCurrentVertex]],
					m_controlPoints[1][m_controlPointIndexArr[lCurrentVertex]],
					m_controlPoints[2][m_controlPointIndexArr[lCurrentVertex]]);
				//UV
				printf("UV: %.2f %.2f\n",
					m_UVCoordinates[0][m_UVCoordinateIndexArr[lCurrentVertex]], //Reads the index correctly, but the answer is wrong
					m_UVCoordinates[1][m_UVCoordinateIndexArr[lCurrentVertex]]);
				//Normals, doesnt use Index right now
				printf("Normal: %.2f %.2f %.2f\n",
					m_normalCoordinateArr[0][lCurrentVertex],
					m_normalCoordinateArr[1][lCurrentVertex],
					m_normalCoordinateArr[2][lCurrentVertex]);
			}
		}
		else if (m_nrOfVerticesPerPolygon == 4)
		{
			//Not used right now, use if mesh is not triangulated
			printf("ERROR: MESH NOT TRIANGULATED");
		}
		printf("\n");		
	}
	printf("\n\n");

	if (m_collision)
		printf("This mesh has collision");
	else
		printf("This mesh has no collision");
	printf("\n");

	if (m_isStatic)
		printf("This mesh is static");
	else
		printf("This mesh is dynamic");
	printf("\n\n");

	printf("Nr of vertices: %i\n\n", m_vertexCount);
}

void MeshData2::setNrOfPolygons(int nrOfPolygons)
{
	m_nrOfPolygons = nrOfPolygons;
}

void MeshData2::setNrOfVerticesPerPolygon(int nrOfVerticesPerPolygon)
{
	m_nrOfVerticesPerPolygon = nrOfVerticesPerPolygon;
}

void MeshData2::setCollision(bool collision)
{
	m_collision = collision;
}

void MeshData2::setStaticMesh(bool staticMesh)
{
	m_isStatic = staticMesh;
}

bool MeshData2::getCollision()const
{
	return m_collision;
}

bool MeshData2::getIsStatic()const
{
	return m_isStatic;
}
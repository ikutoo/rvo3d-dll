#pragma once
#include "API.h"

struct vec3
{
	float x, y, z;
};

extern "C"
{
	RVO_API void rvo_init();
	RVO_API void rvo_doStep();
	RVO_API void rvo_destroy();

	RVO_API void rvo_addAgent(vec3 position);
	RVO_API void rvo_addAgentWithDetails(vec3 position, float neighborDist, size_t maxNeighbors, float timeHorizon, float radius, float maxSpeed);
	RVO_API void rvo_removeAgent(size_t agentNo);

	RVO_API void rvo_setTimeStep(float timeStep);
	RVO_API void rvo_setAgentDefaults(float neighborDist, size_t maxNeighbors, float timeHorizon, float radius, float maxSpeed);
	RVO_API void rvo_setAgentMaxNeighbors(size_t agentNo, size_t maxNeighbors);
	RVO_API void rvo_setAgentMaxSpeed(size_t agentNo, float maxSpeed);
	RVO_API void rvo_setAgentNeighborDist(size_t agentNo, float neighborDist);
	RVO_API void rvo_setAgentPosition(size_t agentNo, vec3 position);
	RVO_API void rvo_setAgentPrefVelocity(size_t agentNo, vec3 prefVelocity);
	RVO_API void rvo_setAgentRadius(size_t agentNo, float radius);
	RVO_API void rvo_setAgentTimeHorizon(size_t agentNo, float timeHorizon);
	RVO_API void rvo_setAgentVelocity(size_t agentNo, vec3 velocity);

	RVO_API size_t rvo_getNumAgents();
	RVO_API size_t rvo_getAgentAgentNeighbor(size_t agentNo, size_t neighborNo);
	RVO_API size_t rvo_getAgentMaxNeighbors(size_t agentNo);
	RVO_API size_t rvo_getAgentNumAgentNeighbors(size_t agentNo);
	RVO_API size_t rvo_getAgentNumORCAPlanes(size_t agentNo);
	RVO_API float rvo_getAgentMaxSpeed(size_t agentNo);
	RVO_API float rvo_getAgentNeighborDist(size_t agentNo);
	RVO_API float rvo_getAgentRadius(size_t agentNo);
	RVO_API float rvo_getAgentTimeHorizon(size_t agentNo);
	RVO_API float rvo_getGlobalTime();
	RVO_API float rvo_getTimeStep();
	RVO_API vec3 rvo_getAgentPosition(size_t agentNo);
	RVO_API vec3 rvo_getAgentPrefVelocity(size_t agentNo);
	RVO_API vec3 rvo_getAgentVelocity(size_t agentNo);
}

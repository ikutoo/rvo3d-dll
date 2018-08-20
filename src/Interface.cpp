#include "Interface.h"
#include "RVOSimulator.h"

static RVO::RVOSimulator* g_pSimulator = nullptr;

static inline RVO::Vector3 __vec2rvoVector(const vec3& vec)
{
	return RVO::Vector3(vec.x, vec.y, vec.z);
}

static inline vec3 __rvoVector2Vec(const RVO::Vector3& vec)
{
	vec3 v = { vec.x(), vec.y(), vec.z() };
	return v;
}

RVO_API void rvo_init()
{
	if (nullptr == g_pSimulator)
		g_pSimulator = new RVO::RVOSimulator();
}

RVO_API void rvo_doStep()
{
	g_pSimulator->doStep();
}

RVO_API void rvo_destroy()
{
	if (g_pSimulator) { delete g_pSimulator; g_pSimulator = nullptr; }
}

RVO_API void rvo_addAgent(vec3 position)
{
	g_pSimulator->addAgent(__vec2rvoVector(position));
}

RVO_API void rvo_addAgentWithDetails(vec3 position, float neighborDist, size_t maxNeighbors, float timeHorizon, float radius, float maxSpeed)
{
	g_pSimulator->addAgent(__vec2rvoVector(position), neighborDist, maxNeighbors, timeHorizon, radius, maxSpeed);
}

RVO_API void rvo_removeAgent(size_t agentNo)
{
	g_pSimulator->removeAgent(agentNo);
}

RVO_API void rvo_setTimeStep(float timeStep)
{
	g_pSimulator->setTimeStep(timeStep);
}

RVO_API void rvo_setAgentDefaults(float neighborDist, size_t maxNeighbors, float timeHorizon, float radius, float maxSpeed)
{
	g_pSimulator->setAgentDefaults(neighborDist, maxNeighbors, timeHorizon, radius, maxSpeed);
}

RVO_API void rvo_setAgentMaxNeighbors(size_t agentNo, size_t maxNeighbors)
{
	g_pSimulator->setAgentMaxNeighbors(agentNo, maxNeighbors);
}

RVO_API void rvo_setAgentMaxSpeed(size_t agentNo, float maxSpeed)
{
	g_pSimulator->setAgentMaxSpeed(agentNo, maxSpeed);
}

RVO_API void rvo_setAgentNeighborDist(size_t agentNo, float neighborDist)
{
	g_pSimulator->setAgentNeighborDist(agentNo, neighborDist);
}

RVO_API void rvo_setAgentPosition(size_t agentNo, vec3 position)
{
	g_pSimulator->setAgentPosition(agentNo, __vec2rvoVector(position));
}

RVO_API void rvo_setAgentPrefVelocity(size_t agentNo, vec3 prefVelocity)
{
	g_pSimulator->setAgentPrefVelocity(agentNo, __vec2rvoVector(prefVelocity));
}

RVO_API void rvo_setAgentRadius(size_t agentNo, float radius)
{
	g_pSimulator->setAgentRadius(agentNo, radius);
}

RVO_API void rvo_setAgentTimeHorizon(size_t agentNo, float timeHorizon)
{
	g_pSimulator->setAgentTimeHorizon(agentNo, timeHorizon);
}

RVO_API void rvo_setAgentVelocity(size_t agentNo, vec3 velocity)
{
	g_pSimulator->setAgentVelocity(agentNo, __vec2rvoVector(velocity));
}

RVO_API size_t rvo_getNumAgents()
{
	return g_pSimulator->getNumAgents();
}

RVO_API size_t rvo_getAgentAgentNeighbor(size_t agentNo, size_t neighborNo)
{
	return g_pSimulator->getAgentAgentNeighbor(agentNo, neighborNo);
}

RVO_API size_t rvo_getAgentMaxNeighbors(size_t agentNo)
{
	return g_pSimulator->getAgentMaxNeighbors(agentNo);
}

RVO_API size_t rvo_getAgentNumAgentNeighbors(size_t agentNo)
{
	return g_pSimulator->getAgentNumAgentNeighbors(agentNo);
}

RVO_API size_t rvo_getAgentNumORCAPlanes(size_t agentNo)
{
	return g_pSimulator->getAgentNumORCAPlanes(agentNo);
}

RVO_API float rvo_getAgentMaxSpeed(size_t agentNo)
{
	return g_pSimulator->getAgentMaxSpeed(agentNo);
}

RVO_API float rvo_getAgentNeighborDist(size_t agentNo)
{
	return g_pSimulator->getAgentNeighborDist(agentNo);
}

RVO_API float rvo_getAgentRadius(size_t agentNo)
{
	return g_pSimulator->getAgentRadius(agentNo);
}

RVO_API float rvo_getAgentTimeHorizon(size_t agentNo)
{
	return g_pSimulator->getAgentTimeHorizon(agentNo);
}

RVO_API float rvo_getGlobalTime()
{
	return g_pSimulator->getGlobalTime();
}

RVO_API float rvo_getTimeStep()
{
	return g_pSimulator->getTimeStep();
}

RVO_API vec3 rvo_getAgentPosition(size_t agentNo)
{
	return __rvoVector2Vec(g_pSimulator->getAgentPosition(agentNo));
}

RVO_API vec3 rvo_getAgentPrefVelocity(size_t agentNo)
{
	return __rvoVector2Vec(g_pSimulator->getAgentPrefVelocity(agentNo));
}

RVO_API vec3 rvo_getAgentVelocity(size_t agentNo)
{
	return __rvoVector2Vec(g_pSimulator->getAgentVelocity(agentNo));
}

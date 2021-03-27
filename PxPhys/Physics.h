#pragma once
#ifdef _WIN32
#define WIN64
#ifdef PXPHYS_EXPORTS
#undef PXPHYS_EXPORTS
#define PXPHYS_EXPORTS __declspec(dllexport)
#else
#define PXPHYS_EXPORTS __declspec(dllimport)
#endif
#else
#define PXPHYS_EXPORTS
#endif

#define PX_CHECKED 1
#define PX_DEBUG 1

namespace physx
{
	class PxFoundation;
	class PxPhysics;
	class PxScene;
	class PxDefaultCpuDispatcher;
	class PxMaterial;
	class PxVec3;
	class PxRigidDynamic;
	class PxControllerManager;
	class PxPvdTransport;
	class PxPvd;
}

class CharacterController;

// TODO: clean up this shit
class PXPHYS_EXPORTS PhysicsObject
{
	friend class PhysicsEngine;

public:
	void SetActor(physx::PxRigidDynamic *actor);
	void GetMx(float *mx);

private:
	physx::PxRigidDynamic *m_actor;
};

// TODO: implement iface!!
class PXPHYS_EXPORTS PhysicsEngine
{

public:
	void Init();
	void Shutdown();
	void Simulate(float dt);
	PhysicsObject *CreateObject(float x, float y, float z, bool kin);
	void DestroyObject(PhysicsObject *obj);

private:
	void CreateScene();
	physx::PxRigidDynamic *CreateBox(const physx::PxVec3 &pos, const physx::PxVec3 &dims, const physx::PxVec3 *linVel, double density, bool kin);
	physx::PxRigidDynamic *CreateSphere(const physx::PxVec3 &pos, double radius, const physx::PxVec3 *linVel, double density, bool kin);

	physx::PxFoundation *m_foundation;
	physx::PxPvdTransport* m_transport;
	physx::PxPvd* m_pvd;
	physx::PxPhysics *m_physics;
	physx::PxScene *m_scene;
	physx::PxDefaultCpuDispatcher *m_cpuDispatcher;
	physx::PxMaterial *m_defaul_material; // TODO: really?
	physx::PxControllerManager *m_characterControllerMgr;
	CharacterController *m_characterController;
};
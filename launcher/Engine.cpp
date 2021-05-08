#include "Engine.h"

#include "common/timer.h"
//#include "Physics.h"
#include "VulkanBackend.h"

void Engine::Initialize(const char * rootPath)
{
    m_rootPath = rootPath;
    //m_physicsEngine = new PhysicsEngine;
    m_renderEngine = new VulkanBackend;

    //m_physicsEngine->Init();
    m_renderEngine->Initialize(m_rootPath.c_str());

    // {
    //     PhysicsObject *box1 = m_physicsEngine->CreateObject(0.f, 1.f, 0.f, false);
    //     float mx1[7];
    //     box1->GetMx(mx1);

    //     RenderObject *rBox1 = m_renderEngine->CreateObject(mx1);
    //     Object obj1;
    //     obj1.pObject = box1;
    //     obj1.rObject = rBox1;
    //     m_objects.push_back(obj1);
    // }
    {
     //   float x = 10.f, y = 0.25f, z = 10.f;
     //   PhysicsObject *box2 = m_physicsEngine->CreateObject(x, y, z, 0.f, -0.125f, 0.f, true);
     //   float mx2[10];
     //   box2->GetMx(mx2);

     //   RenderObject *rBox2 = m_renderEngine->CreateObject(mx2, false);
     //   Object obj2;
     //   obj2.pObject = box2;
     //   obj2.rObject = rBox2;
     //   m_objects.push_back(obj2);
    }//
    {//
     //   float x,y,z;
     //   m_physicsEngine->GetCharacterPos(x, y, z);
     //   float mx2[10];
     //   mx2[0] = 0;
     //   mx2[1] = 0;
     //   mx2[2] = 1;
     //   mx2[3] = 0;
     //   mx2[4] = x;
     //   mx2[5] = y;
     //   mx2[6] = z;
     //   mx2[7] = 1;
     //   mx2[8] = 1;
     //   mx2[9] = 1;
     //   m_character = m_renderEngine->CreateObject(mx2, true);
    }
}

void Engine::Run(){
	cmn::timer _timer;
	int cycles = 0u;
	float elapsed = 0.f;

	do{
		cycles++;
		float delta = _timer.elapsed_time();
		elapsed+=delta;
		_timer.restart();

		if (elapsed > 5.0f){
			printf("FPS: %d for 5 secs\n", cycles/5);
			cycles = 0;
			elapsed = 0.f;
		}
        {
            //m_physicsEngine->MoveCharacter(0,0,0,delta);

 //           float x,y,z;
 //           //m_physicsEngine->GetCharacterPos(x, y, z);
 //           float mx2[10];
 //           mx2[0] = 0;
 //           mx2[1] = 0;
 //           mx2[2] = 1;
 //           mx2[3] = 0;
 //           mx2[4] = x;
 //           mx2[5] = y;
 //           mx2[6] = z;
 //           mx2[7] = 1;
 //           mx2[8] = 1;
 //           mx2[9] = 1;
 //           m_character->Update(mx2);
        }

		//m_physicsEngine->Simulate(delta);

//        for (auto &obj : m_objects){
//            float mx[10];
//            obj.pObject->GetMx(mx);
//            obj.rObject->Update(mx);
//        }

		m_renderEngine->Render(delta);
	}
    while(m_renderEngine->IsRunning());
}

void Engine::Shutdown(){
  //  for (auto& obj : m_objects){
  //      obj.Release(m_physicsEngine);
  //  }
  //  m_physicsEngine->Shutdown();
  //  delete m_physicsEngine;
  //  m_physicsEngine = nullptr;
  //  delete m_renderEngine;
  //  m_renderEngine = nullptr;
}

	
void Engine::Object::Release(PhysicsEngine * physEng){
   // physEng->DestroyObject(this->pObject);
}

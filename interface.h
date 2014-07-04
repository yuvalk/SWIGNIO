#pragma once
#include <Poco/Runnable.h>
#include <Poco/Random.h>
#include <Poco/Thread.h>

namespace example {
/* File : example.h */

class IFrameCB {
	public:
	virtual void newFrame(void)=0;
};

class Monitor : public Poco::Runnable {
	public:
		void mon_init(unsigned char* image_buffer);
		void mon_register(IFrameCB* frameNotify);
		void MainLoop();
		virtual void run();
	private:
		Monitor * mon_this;
		Poco::Thread main_thread;
		unsigned char* buf;
		IFrameCB * frameNotifier = NULL;
		void setMonRegister(IFrameCB* frameNotify);
		void setMonBuf(unsigned char* buffer);
};
}

#include "interface.h"

#include <Poco/Random.h>

void Monitor::MainLoop() {
	Poco::Random::Random rnd
	rnd.seed();

	while (true) {
		Thread::sleep(1000 * rnd.next(10));
		sprintf (buf, "hello %d", rnd.next(10));
		frameNotifier->newFrame();
	}
}

Monitor::init (unsigned char * buffer) {
	buf = buffer;

	Poco::RunnableAdapter<Monitor> runnable(this, &Monitor::MainLoop);
	main_thread.start(runnable);
}

Monitor::register(IFrameCB * frameNotify) {
	frameNotifier = frameNotify;
}


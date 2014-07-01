#include "interface.h"

#include <Poco/Random.h>

#include <stdio.h>

namespace example {
void Monitor::run() {
	Poco::Random rnd;
	rnd.seed();

	while (true) {
		Poco::Thread::sleep(100); // * rnd.next(10));
//		sprintf ((char *)buf, "hello %d", rnd.next(10));
		if (frameNotifier != NULL) frameNotifier->newFrame();
//printf ("!%s!",buf);
	}
}

void Monitor::mon_init (unsigned char* image_buffer) {
printf ("!1!\n");
	buf = image_buffer;

	mon_this = new Monitor();
	main_thread.start(*mon_this);
}

void Monitor::mon_register(IFrameCB* frameNotify) {
	mon_this->setMonRegister(frameNotify);
}

void Monitor::setMonRegister(IFrameCB* frameNotify) {
	frameNotifier = frameNotify;
}
}

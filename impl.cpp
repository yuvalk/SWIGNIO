#include "interface.h"

#include <Poco/Random.h>

#include <stdio.h>

namespace example {
void Monitor::run() {
	Poco::Random rnd;
	rnd.seed();

	while (true) {
		Poco::Thread::sleep(rnd.next(1000));
		sprintf ((char *)buf, "hello %d\n", rnd.next(10));
		if (frameNotifier != NULL) frameNotifier->newFrame();
	}
}

void Monitor::mon_init (unsigned char* image_buffer) {
	buf = image_buffer;

	mon_this = new Monitor();
	mon_this->setMonBuf(buf);
	main_thread.start(*mon_this);
}

void Monitor::mon_register(IFrameCB* frameNotify) {
	mon_this->setMonRegister(frameNotify);
}

void Monitor::setMonBuf(unsigned char* buffer) {
	buf = buffer;
}

void Monitor::setMonRegister(IFrameCB* frameNotify) {
	frameNotifier = frameNotify;
}
}

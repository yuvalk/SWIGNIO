#pragma once

class IFrameCB {
	newFrame();
}

class Monitor() {
	public:
		init (unsigned char * buffer);
		register(IFrameCB * frameNotify);
		void MainLoop();

	private:
		Poco::Thread main_thread;
		unsigned char * buf;
		IFrameCB * frameNotifier;

}

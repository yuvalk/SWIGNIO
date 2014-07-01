import org.kashyoo.swigexample.*;
import java.nio.ByteBuffer;

public class MainExample {
	public class FrameCallback extends IFrameCB {
		public void newFrame() {
			System.out.print("newFrmae!");
		}
	}

	public void do_work() throws InterruptedException {
		java.nio.ByteBuffer buf = ByteBuffer.allocateDirect(100);

		FrameCallback cb=this.new FrameCallback();
		Monitor mon=new Monitor();
		mon.mon_init(buf);
		Thread.sleep(100);
System.out.print("!2!");
		mon.mon_register(cb);
		while (true) {
		}
	}

	public static void main(String argv[]) throws InterruptedException {
		System.loadLibrary("example");

		MainExample main = new MainExample(); 
		main.do_work();
	}
}

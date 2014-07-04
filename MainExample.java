import org.kashyoo.swigexample.*;
import java.nio.ByteBuffer;

import java.io.*;  
import java.nio.*;  
import java.nio.channels.*;  
import java.nio.charset.*; 

public class MainExample {
	static java.nio.ByteBuffer buf = ByteBuffer.allocateDirect(100);
	public class FrameCallback extends IFrameCB {
		public void newFrame() {
			System.out.print("newFrmae!");
			try {
				Charset charset = Charset.defaultCharset();  
				CharsetDecoder decoder = charset.newDecoder();  
				CharBuffer charBuffer = decoder.decode(MainExample.buf);  
				System.out.print(charBuffer.toString());
				MainExample.buf.clear();
			} catch (java.io.IOException ex) {
			}
		}
	}

	public void do_work() throws InterruptedException {

		FrameCallback cb=this.new FrameCallback();
		Monitor mon=new Monitor();
		mon.mon_init(MainExample.buf);
		Thread.sleep(100);
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

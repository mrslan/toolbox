package tutorial;

import com.nativelibs4java.opencl.*;
import com.nativelibs4java.opencl.CLMem.Usage;
import com.nativelibs4java.util.*;
import org.bridj.Pointer;
import java.nio.ByteOrder;
import static org.bridj.Pointer.*;
import java.io.IOException;

public class JavaCLTutorial1 {
    public static void main(String[] args) throws IOException {
        CLContext context = JavaCL.createBestContext();
        CLQueue queue = context.createDefaultQueue();
        ByteOrder byteOrder = context.getByteOrder();
        
        int n = 1024;
        Pointer<Float>
            aPtr = allocateFloats(n).order(byteOrder),
            bPtr = allocateFloats(n).order(byteOrder);

        for (int i = 0; i < n; i++) {
            aPtr.set(i, (float) i/2);
            bPtr.set(i, (float) i/2);
        }

        // Create OpenCL input buffers (using the native memory pointers aPtr and bPtr) :
        CLBuffer<Float> 
            a = context.createFloatBuffer(Usage.Input, aPtr),
            b = context.createFloatBuffer(Usage.Input, bPtr);

        // Create an OpenCL output buffer :
        CLBuffer<Float> out = context.createFloatBuffer(Usage.Output, n);

        // Read the program sources and compile them :
        String src = IOUtils.readText(JavaCLTutorial1.class.getResource("TutorialKernels.cl"));
        CLProgram program = context.createProgram(src);

        // Get and call the kernel :
        CLKernel addFloatsKernel = program.createKernel("add_floats");
        addFloatsKernel.setArgs(a, b, out, n);
        int[] globalSizes = new int[] { n };
        CLEvent addEvt = addFloatsKernel.enqueueNDRange(queue, globalSizes);
        
        Pointer<Float> outPtr = out.read(queue, addEvt); // blocks until add_floats finished

        // Print the first 10 output values :
        for (int i = 0; i < 10 && i < n; i++)
            System.out.println("out[" + i + "] = " + outPtr.get(i));
        
    }
}
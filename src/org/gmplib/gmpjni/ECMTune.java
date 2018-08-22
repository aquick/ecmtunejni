package org.gmplib.gmpjni;

import android.util.Log;

/**
 * Java interface to bench_mulredc and tune programs of ECM library.  @see ecm.gforge.inria.fr/
 */
public class ECMTune {

    /**
     * Load native libraries.
     */
    public static void init(String rp)
    {
	Log.d( "ecmtunejni", "loading native libs" );
	System.loadLibrary("c++_shared");
	System.loadLibrary("gmp");
	System.loadLibrary("ecmtunejni");
	root = rp;
    }

    private static String root; /* root path for files */

    private static void checkUnsignedIntRange(long y)
    {
	if (y < 0 || y >= 0x100000000L) {
	    throw new IllegalArgumentException("Parameter out of range");
	}
    }

    public static native void bench_mulredc(int verbose, int minsize, int maxsize, String outfilename, String errfilename);

    public static void bench_mulredc()
    {
	bench_mulredc(0, -1, -1, root + "/bench_mulredc_out.txt", root + "/bench_mulredc_err.txt");
    }

    public static void bench_mulredc(int verbose)
    {
	bench_mulredc(verbose, -1, -1, root + "/bench_mulredc_out.txt", root + "/bench_mulredc_err.txt");
    }

    private static native void native_tune(int verbose, int min_log2_len, int max_log2_len, long seed, String outfilename, String errfilename);
    public static void tune(int verbose, int min_log2_len, int max_log2_len, long seed, String outfilename, String errfilename)
    {
	checkUnsignedIntRange(seed);
	native_tune(verbose, min_log2_len, max_log2_len, seed, outfilename, errfilename);
    }

    public static void tune()
    {
	tune(0, -1, -1, 0, root + "/tune_out.txt", root + "/tune_err.txt");
    }

    public static void tune(int verbose, long seed)
    {
	tune(verbose, -1, -1, seed, root + "/tune_out.txt", root + "/tune_err.txt");
    }

}

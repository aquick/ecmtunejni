#include "org_gmplib_gmpjni_ECMTune.h"

#ifdef __cplusplus
extern "C" {
#endif
int bench_main(int verbose, int minsize, int maxsize, const char *outfname, const char *errfname);
int tune_main(int verbose, int min_log2_len, int max_log2_len, unsigned long int seed, const char *outfname, const char *errfname);
#ifdef __cplusplus
}
#endif

/*
 * Class:     org_gmplib_gmpjni_ECMTune
 * Method:    bench_mulredc
 * Signature: (IIILjava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_gmplib_gmpjni_ECMTune_bench_1mulredc
  (JNIEnv *env, jclass, jint verbose, jint minsize, jint maxsize, jstring outfname, jstring errfname)
{
    jboolean is_copy;
    const char *outfname_chars = env->GetStringUTFChars(outfname, &is_copy);
    const char *errfname_chars = env->GetStringUTFChars(errfname, &is_copy);

    bench_main(verbose, minsize, maxsize, outfname_chars, errfname_chars);
    env->ReleaseStringUTFChars(outfname, outfname_chars);
    env->ReleaseStringUTFChars(errfname, errfname_chars);
}

/*
 * Class:     org_gmplib_gmpjni_ECMTune
 * Method:    tune
 * Signature: (IIIJLjava/lang/String;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_org_gmplib_gmpjni_ECMTune_native_1tune
  (JNIEnv *env, jclass, jint verbose, jint min_log2_len, jint max_log2_len, jlong seed, jstring outfname, jstring errfname)
{
    jboolean is_copy;
    const char *outfname_chars = env->GetStringUTFChars(outfname, &is_copy);
    const char *errfname_chars = env->GetStringUTFChars(errfname, &is_copy);

    tune_main(verbose, min_log2_len, max_log2_len, static_cast<unsigned long int>(seed), outfname_chars, errfname_chars);
    env->ReleaseStringUTFChars(outfname, outfname_chars);
    env->ReleaseStringUTFChars(errfname, errfname_chars);
}

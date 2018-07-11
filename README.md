# Emscripten-build
These are the build steps that I followed on an Intel i7 machine running Ubuntu 16.04.3. Please suggest if I am doing anything wrong with the build itself:

Built emscripten SDK exactly as mentioned in this [link](https://kripken.github.io/emscripten-site/docs/getting_started/downloads.html) I have all the software prerequisites as mentioned there.

As mentioned [here](https://github.com/kripken/emscripten/wiki/Pthreads-with-WebAssembly), cloned the incoming branch of emscripten using below command:
./emsdk install sdk-incoming-64bit (this is mentioned [here](https://kripken.github.io/emscripten-site/docs/tools_reference/emsdk.html) )

Downloaded the Firefox nightly version 62 and 63 and set javascript.options.shared_memory boolean variable to “true”.

Compiled a pthread_create hello world example as following:
emcc -g thread.c -s USE_PTHREADS=1 -s WASM=1 -o thread.html --memory-init-file 1

Launched program.html generated above in both the Firefox nightly versions that always shows :
Preallocating 1 workers for a pthread spawn pool.
Preallocating 1 workers for a pthread spawn pool.
with a constant "running" sign for too long.

While running node program.js gives me :

/Users/priysha/emsdk/emscripten/incoming/mutex.js:106

  throw ex;

  ^

  TypeError: [object Uint32Array] is not an integer shared typed array.
  at Atomics.store ()
  at Object.initMainThreadBlock (/Users/priysha/emsdk/emscripten/incoming/mutex.js:1821:17)
  at Object. (/Users/priysha/emsdk/emscripten/incoming/mutex.js:5651:38)
  at Module._compile (internal/modules/cjs/loader.js:689:30)
  at Object.Module._extensions..js (internal/modules/cjs/loader.js:700:10)
  at Module.load (internal/modules/cjs/loader.js:599:32)
  at tryModuleLoad (internal/modules/cjs/loader.js:538:12)
  at Function.Module._load (internal/modules/cjs/loader.js:530:3)
  at Function.Module.runMain (internal/modules/cjs/loader.js:742:12)
  at startup (internal/bootstrap/node.js:236:19)


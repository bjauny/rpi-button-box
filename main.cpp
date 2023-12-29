#include <circle/startup.h>

#include "kernel.h"

int main() {
    CKernel kernel{};
    if (!kernel.Initialize ())
	{
		halt ();
		return EXIT_HALT;
	}
	
	EShutdownMode shutdownMode = kernel.Run();

	switch (shutdownMode)
	{
	case EShutdownMode::ShutdownReboot:
		reboot();
		return EXIT_REBOOT;

	case EShutdownMode::ShutdownHalt:
	default:
		halt();
		return EXIT_HALT;
	}
}
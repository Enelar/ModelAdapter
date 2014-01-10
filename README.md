<p>
T-Soft ltd. physical factory model adapter.<br />
Main purpose: forget about backward compatibility, formulate a standard interface.
</p>

Modules:
* PipeExport - .dll model connector, using original headers and original pipe interface. Builds only in VS2005
* PipeExport/Test - .exe test project, builds only in VS2005
* PipeReleased - .lib interface, that translate independent names to internal model structures.
* ModelAdapter - .exe test project for testing PipeReleased
* ModelProxy - .dll that represents new, light interface
* ExceptionSafeModel - .dll that use ModelProxy with exception safe way, mean never crash
* ExceptionSafeDebug - .exe that tests stability of ExceptionSafeModel

* UnitySimulator - c# project, that tests how ExceptionSafeModel works in c#
* New Unity Project - dummy unity project, that test how ExceptionSafeModel works in Unity3d.

* ASN1 - .lib Serialisation/Deserialisation library (Used by PipeReleased and ModelProxy)
* AX - .lib dependencies for ASN1 and PipeReleased
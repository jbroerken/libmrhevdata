MRH_EvD_Sys_ResetRequest_U_t
============================
The MRH_EvD_Sys_ResetRequest_U_t struct represents the data 
for a user application system request.

Header
------
The struct definition can be found in the following file:

.. code-block:: c

    #include <libmrhevdata/Version/1/MRH_EvSystem_V1.h>


Variables
---------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - p_PackagePath
      - The package path buffer containing the application 
	    package path.
      

Remarks
-------
* The package path buffer is static in size.
* The static package buffer buffer size is defined by :doc:`../../../../../../Macros/libmrhevdata_Directory/Version/1/MRH_EvSystem_V1/MRH_EVD_SYS_STRING_BUFFER_MAX_TERMINATED`.
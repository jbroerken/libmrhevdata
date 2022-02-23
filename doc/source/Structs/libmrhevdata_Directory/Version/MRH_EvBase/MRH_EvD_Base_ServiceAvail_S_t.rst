MRH_EvD_Base_ServiceAvail_S_t
=============================
The MRH_EvD_Base_ServiceAvail_S_t struct represents the data 
for a service available event sent by platform services.

Header
------
The struct definition can be found in the following file:

.. code-block:: c

    #include <libmrhevdata/Version/MRH_EvBase.h>


Variables
---------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - u8_Available
      - If the service is usable or not.
    * - u32_SupplierID
      - The service supplier identifier.
    * - u32_BinaryID
      - The service binary identifier.
    * - u32_Version
      - The service version.
      

Remarks
-------
None.
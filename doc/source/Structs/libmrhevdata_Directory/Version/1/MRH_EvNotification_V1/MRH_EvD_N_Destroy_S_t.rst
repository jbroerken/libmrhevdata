MRH_EvD_N_Destroy_S_t
=====================
The MRH_EvD_N_Destroy_S_t struct represents the data for a 
event containing a notification destruction result.

Header
------
The struct definition can be found in the following file:

.. code-block:: c

    #include <libmrhevdata/Version/1/MRH_EvNotification_V1.h>


Variables
---------
.. list-table::
    :header-rows: 1

    * - Parameter
      - Description
    * - u8_Result
      - The destruction result.
    * - u32_Key
      - The key for the destroyed notification.
      

Remarks
-------
* The result is defined by :doc:`../../../../../../Enumerations/libmrhevdata_Directory/Version/MRH_EvBase/MRH_EvD_Base_Result`.
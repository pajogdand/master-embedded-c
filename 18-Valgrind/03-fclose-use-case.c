#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SH_RESP_BUF_LEN 512

typedef struct _pcie_dev_loc_info
{
	int domain_num;
	int bus_num;
	int slot_num;
	int model_num;
} pcie_dev_loc_info;

/* 
 * This function locates the PCI Express device and fills in its location information
 * in the 'ppcie_dev_loc' structure.
 */
bool locate_pcie_dev(pcie_dev_loc_info* ppcie_dev_loc)
{
	bool found = false;
	bool found_qc = false;
	char resp[SH_RESP_BUF_LEN] = "";

	// Execute the 'lspci' command to retrieve PCI device information
	FILE * fp = popen("sample.txt", "r");
	if (!fp)
		return false;

	// Close the file pointer
	// int ret = pclose(fp);
	// if (ret == -1)
	// 	return false;

    pclose(fp);
	// Return success or failure based on the result
	return found;
}

int main(void)
{
    // pcie_dev_loc_info dev_loc;

    // if (locate_pcie_dev(&dev_loc))
    // {
    //     printf("PCIe device located:\n");
    //     // printf("Domain number: %d\n", dev_loc.domain_num);
    //     // printf("Bus number: %d\n", dev_loc.bus_num);
    //     // printf("Slot number: %d\n", dev_loc.slot_num);
    //     // printf("Model number: %d\n", dev_loc.model_num);
    // }
    // else
    // {
    //     printf("Failed to locate PCIe device.\n");
    // }

    FILE * fp = popen("./sample.txt", "r");
	// if (!fp)
	// 	return false;
    
    pclose(fp);

    return 0;
}


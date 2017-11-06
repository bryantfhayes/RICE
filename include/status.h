#define csys_status_success 0x00000000
#define csys_status_failure 0x80000000
#define csys_err_nullParam 0x80000001
#define csys_err_allocFailed 0x80000002
#define cm_status_isFailed(x) ((x) > 0x80000000)
#define cm_status_returnIfFailed(status) do { int stat = (status); if (cm_status_isFailed(stat)) return stat; } while(0)
#define cm_status_return(status) do { return (status); } while(0)
#define cm_status_returnError(stat,err) do { return (err); } while(0)
typedef int csys_status;
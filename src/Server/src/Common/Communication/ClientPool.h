/*
 * ClientPool.h
 *
 *  Created on: 2014年1月24日
 *      Author: tmdjojo
 */

#ifndef CLIENTPOOL_H_
#define CLIENTPOOL_H_

#include "./Client.h"
#include "../Type.h"

#define MAX_CLIENT_SIZE    64  ////max connects

class ClientPool {
public:
	ClientPool();
	virtual ~ClientPool();
	BOOL Init();
	inline Client* GetClient(UINT index){
	    return (index >= MAX_CLIENT_SIZE)?NULL:&client_pool_[index];
	}
private:
	Client client_pool_[MAX_CLIENT_SIZE];

};
extern ClientPool* g_client_pool;
#endif /* CLIENTPOOL_H_ */

#pragma once

namespace cc {
	
	class ConnectInfo : noncopyable
	{
	public:
		int32_t getConnectErrorId();
		int32_t getConnectId();
		int32_t getTimeoutId();
		
		int32_t getDisconnectId();
		int32_t getExceptionId();
		int16_t getDispatchId();
		
		template<class T>
		void serialize(T * nSerialize, int8_t nCount)
		{
			nSerialize->runNumber(mConnectInfoId, "connectInfoId");
			
			nSerialize->runNumber(mConnectErrorId, "connectErrorId");
			nSerialize->runNumber(mConnectId, "connectId");
			nSerialize->runNumber(mTimeoutId, "timeoutId");
			
			nSerialize->runNumber(mDisconnectId, "disconnectId");
			nSerialize->runNumber(mExceptionId, "exceptionId");
			nSerialize->runNumber(mDispatchId, "dispatchId");
		}
		bool isDefault();
		int16_t getKey();
		
		ConnectInfo();
		~ConnectInfo();
		
	private:
		int16_t mConnectInfoId;
		
		int32_t mConnectErrorId;
		int32_t mConnectId;
		int32_t mTimeoutId;
		
		int32_t mDisconnectId;
		int32_t mExceptionId;
		int16_t mDispatchId;
	};
	typedef std::shared_ptr<ConnectInfo> ConnectInfoPtr;
	
}

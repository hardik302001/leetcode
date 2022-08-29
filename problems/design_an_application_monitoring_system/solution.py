# idk how to do this ques, submitted for testing

"""
Functional requimrents
Need to return percentile latency
    Need to store latencies for an app and api
Need to return top errors
    Need to store error-counts for an app and api

Non-functional requirements
logLatency and logError will be called many times, so they should be very fast
getPercentileLatency and getTopErrors will depend on the users discretion. We'll see how much we can optimize either then discuss with the user
getPercentileLatency - O(1) if latencies are always sorted, but keeping it sorted is makes logs O(n).  O(nlogn) if not sorted.
getTopErrors - O(1) if error numbers and counts are always sorted, but keeping it sorted makes logs O(n). O(nlogn) if not sorted.

If user wants to constantly watch getPercentileLatency and getTopErrors, then it makes sense to keep logs sorted.  Otherwise, we sort on demand. It's unlikely that someone will watch getPercentileLatency and getTopErrors, so let's prioritize an O(1) for logging.
"""
class MonitoringSystem:

    def __init__(self):
        self.app_api_to_latencies = defaultdict(list)
        self.app_api_to_errors_and_counts = defaultdict(lambda: defaultdict(int))
        self.app_to_apis = defaultdict(set)

    def logLatency(self, applicationName: str, api: str, latencyInMills: int) -> None:
        self.app_api_to_latencies[(applicationName, api)].append(latencyInMills)
        self.app_to_apis[applicationName].add(api)

    def logError(self, applicationName: str, api: str, errorCode: int) -> None:
        self.app_api_to_errors_and_counts[(applicationName, api)][errorCode] += 1
        self.app_to_apis[applicationName].add(api)

    def getPercentileLatency(self, percentile: int, applicationName: str, api: str) -> int:
        latencies_for_app_api = self.app_api_to_latencies[(applicationName,api)]
        
        if latencies_for_app_api:
            index = max(0, (percentile * len(latencies_for_app_api) // 100) - 1)
            latencies_for_app_api.sort()
            return latencies_for_app_api[index]
        else:
            latencies_for_app = []
            for api in self.app_to_apis[applicationName]:
                latencies_for_app_api = self.app_api_to_latencies[(applicationName,api)]
                latencies_for_app += latencies_for_app_api
            latencies_for_app.sort()
            index = max(0, (percentile * len(latencies_for_app) // 100) - 1)
            return latencies_for_app[index]

    def getTopErrors(self, applicationName: str, api: str) -> List[int]:
        app_api_errors = self.app_api_to_errors_and_counts[(applicationName, api)]
        max_heap = [(-ct, error_code) for error_code, ct in app_api_errors.items()]
        if len(max_heap) < 3:
            max_heap = []
            for api in self.app_to_apis[applicationName]:
                app_api_errors = self.app_api_to_errors_and_counts[(applicationName, api)]
                max_heap += [(-ct, error_code) for error_code, ct in app_api_errors.items()]
        heapq.heapify(max_heap)            
        return [heapq.heappop(max_heap)[1] for _ in range(3)]
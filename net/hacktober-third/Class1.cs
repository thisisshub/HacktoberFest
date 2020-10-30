using System;

namespace hacktober_third
{
    public static class HttpRequestExtensions
    {
        public static string GetBearerToken(this HttpRequest request)
        {
            const string AUTH_HEADER_NAME = "Authorization";
            const string BEARER_PREFIX = "Bearer";

            if (request == null) return string.Empty;
            if (request.Headers.ContainsKey(AUTH_HEADER_NAME) == false) return string.Empty;
            if (request.Headers[AUTH_HEADER_NAME].ToString().StartsWith(BEARER_PREFIX) == false) return string.Empty;

            return request.Headers[AUTH_HEADER_NAME].ToString().Substring(BEARER_PREFIX.Length).Trim();
        }

        public static int GetAuthenticatedUserId(this HttpRequest request)
        {
            var token = request.GetBearerToken();
            var claims = AccessTokenManager.ExtractClaims(token);

            if (claims.ContainsKey("userId") == false) return 0;
            if (int.TryParse(claims["userId"], out int userId) == false) return 0;

            return userId;
        }

        public static async Task<dynamic> ExtractBodyAsync(this HttpRequest request)
        {
            return await ExtractBodyAsync<dynamic>(request);
        }

        public static async Task<T> ExtractBodyAsync<T>(this HttpRequest request) where T : class
        {
            var requestBody = await new StreamReader(request.Body).ReadToEndAsync();
            return JsonConvert.DeserializeObject<T>(requestBody);
        }
    }
}

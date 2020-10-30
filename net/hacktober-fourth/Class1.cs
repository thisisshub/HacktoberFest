using System;

namespace hacktober_fourth
{
    public static class AccessTokenManager
    {
        static AccessTokenManager()
        {
            _jwtIssuerSigningKey = Environment.GetEnvironmentVariable("JwtIssuerSigningKey");
            _jwtAudience = Environment.GetEnvironmentVariable("JwtAudience");
            _jwtIssuer = Environment.GetEnvironmentVariable("JwtIssuer");
        }

        private readonly static string _jwtIssuerSigningKey;
        private readonly static string _jwtAudience;
        private readonly static string _jwtIssuer;

        public static string CreateToken(User user)
        {
            if (user == null)
            {
                throw new Exception("Can't create jwt, user is null.");
            }

            var claims = new[]
            {
                new Claim("email", user.Email),
                new Claim("userId", user.Id.ToString()),
                new Claim("uniqueId", user.UniqueId.ToString()),
                new Claim("userType", user.UserType.ToString()),
                new Claim("fullName", user.FullName),
                new Claim("verified", user.Verified.ToString())
            };

            var key = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(_jwtIssuerSigningKey));
            var creds = new SigningCredentials(key, SecurityAlgorithms.HmacSha256Signature);
            var token = new JwtSecurityToken(_jwtIssuer, _jwtAudience, claims, expires: DateTime.Now.AddHours(24), signingCredentials: creds);

            return new JwtSecurityTokenHandler().WriteToken(token);
        }

        public static Dictionary<string, string> ExtractClaims(string token)
        {
            var handler = new JwtSecurityTokenHandler();
            var jwt = handler.ReadJwtToken(token);

            var claims = new Dictionary<string, string>();
            foreach (var claim in jwt.Claims)
            {
                claims.Add(claim.Type, claim.Value);
            }

            return claims;
        }

        public static AccessTokenResult ValidateToken(string token)
        {
            try
            {
                if (string.IsNullOrEmpty(token))
                {
                    return AccessTokenResult.NoToken();
                }

                var tokenParams = new TokenValidationParameters()
                {
                    RequireSignedTokens = true,
                    ValidAudience = _jwtAudience,
                    ValidateAudience = true,
                    ValidIssuer = _jwtIssuer,
                    ValidateIssuer = true,
                    ValidateIssuerSigningKey = true,
                    ValidateLifetime = true,
                    IssuerSigningKey = new SymmetricSecurityKey(Encoding.UTF8.GetBytes(_jwtIssuerSigningKey))
                };

                // Validate the token
                var handler = new JwtSecurityTokenHandler();
                var result = handler.ValidateToken(token, tokenParams, out var securityToken);
                return AccessTokenResult.Success(result);

            }
            catch (SecurityTokenExpiredException)
            {
                return AccessTokenResult.Expired();
            }
            catch (Exception ex)
            {
                return AccessTokenResult.Error(ex);
            }
        }
    }
}

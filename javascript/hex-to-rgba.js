const hexToRGB = (hex, alpha) => {
  const r = parseInt(hex.slice(1, 3), 16);
  const g = parseInt(hex.slice(3, 5), 16);
  const b = parseInt(hex.slice(5, 7), 16);

  const payload = `rgba(${r},${g},${b}, ${alpha || 1})`;

  return payload;
};

export default hexToRGB;

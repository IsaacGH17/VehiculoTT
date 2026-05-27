#define MPU6050_ADDR      (0x68 << 1)

#define WHO_AM_I_REG      0x75
#define PWR_MGMT_1        0x6B
#define SMPLRT_DIV        0x19
#define CONFIG            0x1A
#define GYRO_CONFIG       0x1B
#define ACCEL_CONFIG      0x1C

#define ACCEL_XOUT_H      0x3B
#define GYRO_XOUT_H       0x43

I2C_HandleTypeDef hi2c1;

void MPU6050_Init(void)
{
    uint8_t data;
    uint8_t id;
    HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, WHO_AM_I_REG, I2C_MEMADD_SIZE_8BIT, &id, 1, 200);
    HAL_Delay(100);
    data = 0x00;
    HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, PWR_MGMT_1, I2C_MEMADD_SIZE_8BIT, &data, 1, 200);
    HAL_Delay(100);
    data = 0x00;
    HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, SMPLRT_DIV, I2C_MEMADD_SIZE_8BIT, &data, 1, 200);
    data = 0x03;
    HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, CONFIG, I2C_MEMADD_SIZE_8BIT,  &data,  1, 200);
    data = 0x00;
    HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, GYRO_CONFIG, I2C_MEMADD_SIZE_8BIT, &data, 1, 200);
    data = 0x00;
    HAL_I2C_Mem_Write(&hi2c1, MPU6050_ADDR, ACCEL_CONFIG, I2C_MEMADD_SIZE_8BIT, &data, 1, 200);
    HAL_Delay(200);
}

void MPU6050_Read(int16_t *ax, int16_t *ay, int16_t *az,
                  int16_t *gx, int16_t *gy, int16_t *gz)
{
    uint8_t raw[14];
    HAL_I2C_Mem_Read(&hi2c1, MPU6050_ADDR, ACCEL_XOUT_H, I2C_MEMADD_SIZE_8BIT, raw, 14, 200);
    *ax = (int16_t)(raw[0] << 8 | raw[1]);
    *ay = (int16_t)(raw[2] << 8 | raw[3]);
    *az = (int16_t)(raw[4] << 8 | raw[5]);
    *gx = (int16_t)(raw[8] << 8 | raw[9]);
    *gy = (int16_t)(raw[10] << 8 | raw[11]);
    *gz = (int16_t)(raw[12] << 8 | raw[13]);
}

/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 */

#include <zephyr/kernel.h>
#include <zephyr/usb/usb_device.h>
#include <zephyr/usb/usbd.h>
#include <zephyr/drivers/uart.h>

int main(void)
{

	int ret;

	const struct device *usb_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_shell_uart));

	uint32_t dtr = 0;

	if (usb_enable(NULL))
	{
		return;
	}

	// Sleep to wait for a terminal connection.
	k_sleep(K_MSEC(2500));
	uart_line_ctrl_get(usb_dev, UART_LINE_CTRL_DTR, &dtr);
	k_sleep(K_MSEC(2500));
	return 0;
}
